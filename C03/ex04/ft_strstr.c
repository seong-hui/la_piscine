/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:55:16 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/18 14:31:35 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	count_j(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < ft_strlen1(to_find))
	{
		if (str[i + j] == to_find[j])
			j++;
		else
			break ;
	}
	return (j);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (ft_strlen1(to_find) == 0)
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			j = count_j(&str[i], to_find);
			if (j == ft_strlen1(to_find))
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
 
int main(void)
{
   char *string1 = "";
   char *string2 = "";
   char *result;
	//printf("%d %d\n", ft_strlen1(), ft_strlen1(to_find));
   result = ft_strstr(string1,string2);
   printf("%s\n", result);
   result = strstr(string1,string2);
   printf("%s\n", result);
}*/