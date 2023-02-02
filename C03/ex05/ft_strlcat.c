/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:19:05 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/18 14:31:38 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	int				i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[i] && dest_len + i + 1 < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char src[100] = "asfasdf";
	char dst[100] = "goods";
	char src1[100] = "asfasdf";
	char dst1[100] = "goods";
	printf("strlcat return 	  : %ld, dst : %s\n", strlcat(dst,src,4), dst);	
	printf("ft_strlcat return : %u, dst : %s\n", ft_strlcat(dst1,src1,4), dst);
}*/