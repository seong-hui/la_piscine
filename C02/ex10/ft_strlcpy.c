/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:15:20 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/16 18:21:53 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len);
	if (len == 0)
	{
		dest[0] = '\0';
		return (0);
	}
	while (i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char src[] = "das";
	char dst[] = "goods";
	char src1[] = "das";
	char dst1[] = "goods";
	printf("strlcpy return 	  : %ld, dst : %s\n", strlcpy(dst,src,0), dst);	
	printf("ft_strlcpy return : %u, dst : %s\n", ft_strlcpy(dst1,src1,0), dst);
}
*/