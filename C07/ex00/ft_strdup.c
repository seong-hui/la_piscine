/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:59:23 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/25 19:14:46 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*p;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (len == 0)
	{
		p = (char *)malloc(sizeof(char) * 1);
		p[0] = '\0';
		return (p);
	}
	p = (char *)malloc(sizeof(char) * len + 1);
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*
#include <stdio.h>
int main()
{
	char str[] = "";
	printf("%s", ft_strdup(str));
}*/