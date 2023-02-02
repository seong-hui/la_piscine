/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 02:05:08 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/22 15:23:49 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main()
{
	printf("sqrt of %d is %d\n", -1421, ft_sqrt(-1421));
	printf("sqrt of %d is %d\n", 0, ft_sqrt(0));
    printf("sqrt of %d is %d\n", 1, ft_sqrt(1));
    printf("sqrt of %d is %d\n", 2, ft_sqrt(2));
	printf("sqrt of %d is %d\n", 4, ft_sqrt(4));
	printf("sqrt of %d is %d\n", 16, ft_sqrt(16));
	printf("sqrt of %d is %d\n", 828122545, ft_sqrt(828122545));
	printf("sqrt of %d is %d\n", 1712138884, ft_sqrt(1712138884));
    printf("sqrt of %d is %d\n", 449793369, ft_sqrt(449793369));
	printf("sqrt of %d is %d\n", 1640045925, ft_sqrt(1640045925));
        printf("sqrt of %d is %d\n", 2147395600, ft_sqrt(2147395600));
        printf("sqrt of %d is %d\n", 2147483646, ft_sqrt(2147483646));
        printf("sqrt of %d is %d\n", 75759616, ft_sqrt(75759616));
        printf("sqrt of %d is %d\n", 1112253864, ft_sqrt(1112253864));
        printf("sqrt of %d is %d\n", 1599360064, ft_sqrt(1599360064));
        printf("sqrt of %d is %d\n", 1818985313, ft_sqrt(1818985313));
        printf("sqrt of %d is %d\n", 1589297956, ft_sqrt(1589297956));
        printf("sqrt of %d is %d\n", 467794402, ft_sqrt(467794402));
        printf("sqrt of %d is %d\n", 1780502416, ft_sqrt(1780502416));
        printf("sqrt of %d is %d\n", 1728805277, ft_sqrt(1728805277));
}*/