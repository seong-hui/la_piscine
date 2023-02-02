/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:09:24 by seonghmo          #+#    #+#             */
/*   Updated: 2023/02/02 04:12:36 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	in_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && in_charset(charset, str[i]) == 0)
		i++;
	return (i);
}

int	count_str(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (in_charset(charset, str[i]) && str[i])
			i++;
		if (str[i] != '\0')
			cnt++;
		while (in_charset(charset, str[i]) == 0 && str[i])
			i++;
	}
	return (cnt);
}

char	*put_str(char *str, char *charset, int *index, t_map_info info)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	while (in_charset(charset, str[*index]) && str[*index])
		*index += 1;
	len = ft_strlen(str + *index, charset);
	if (info.col != len)
		return (0);
	word = (char *)malloc(sizeof(char) * len + 1);
	while (str[*index] && in_charset(charset, str[*index]) == 0)
	{
		if (str[*index] != info.empty && str[*index] != info.obstacle)
			return (0);
		word[i] = str[*index];
		*index += 1;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset, t_map_info info)
{
	int		cnt;
	char	**p;
	int		i;
	int		index;

	index = 0;
	cnt = count_str(str, charset);
	if (cnt != info.row)
		return (0);
	p = (char **)malloc(sizeof(char *) * (cnt + 1));
	i = 0;
	while (i < cnt)
	{
		p[i] = put_str(str, charset, &index, info);
		if (!p[i])
			return (0);
		i++;
	}
	p[cnt] = 0;
	return (p);
}
