/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:18:07 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/26 01:34:10 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = '\0';
	return (dest);
}

int	len_str(char **strs, char *sep, int size)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += ft_strlen(sep) * (size - 1);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*p;
	int		i;

	if (size <= 0)
	{
		p = (char *)malloc(sizeof(char) * 1);
		p[0] = '\0';
		return (p);
	}
	len = len_str(strs, sep, size);
	p = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	p[0] = '\0';
	while (i < size)
	{
		ft_strcat(p, strs[i]);
		if (i != size - 1)
			ft_strcat(p, sep);
		i++;
	}
	p[len] = '\0';
	return (p);
}

/*
#include <stdio.h>
int main()
{
	char *str[] = {"hi", "hello","bye"};
	char *sep = "!!";
	char *words;

	words = ft_strjoin(3, str, sep);
		printf("%s\n", words);
}*/