/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:11:41 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/16 02:57:46 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
 
#define SIZE 40
int main(void)
{
  char source1[ SIZE ] = "123456789";
  char destination1[ SIZE ] = "abcdefg";
  char * return_string;
  int    index = 4;
 
  printf( "destination1 is originally = '%s'\n", destination1 );
  return_string = ft_strncpy( destination1, source1, index );
  printf( "After strncpy, destination1 becomes '%s'\n", return_string );
}
*/