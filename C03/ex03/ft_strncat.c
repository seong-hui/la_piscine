/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:46:04 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/18 14:30:40 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = 0;
	while (dest[dest_len])
		dest_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (src_len < nb)
		nb = src_len;
	src_len = 0;
	while (src_len < nb)
	{
		dest[dest_len++] = src[src_len++];
	}
	dest[dest_len] = '\0';
	return (dest);
}

/*
#include <stdio.h>
int main()
{
	char a[100] = "1234";
	char b[] = "abcd";
	printf("%s", ft_strncat(a, b, 6));
}*/