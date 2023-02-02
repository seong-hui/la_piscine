/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:51:37 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/22 14:33:40 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i ++;
	}
	return (1);
}

/*
#include <stdio.h>

int main()
{
	printf("%d -> %d\n", -1620, ft_is_prime(-1620));
    printf("%d -> %d\n", -12, ft_is_prime(-12));
    printf("%d -> %d\n", 0, ft_is_prime(0));
    printf("%d -> %d\n", 1, ft_is_prime(1));
    printf("%d -> %d\n", 2, ft_is_prime(2));
	printf("%d -> %d\n", 3, ft_is_prime(3));
    printf("%d -> %d\n", 4219, ft_is_prime(4219));
    printf("%d -> %d\n", 7853, ft_is_prime(7853));
    printf("%d -> %d\n", 78989, ft_is_prime(78989));
    printf("%d -> %d\n", 2147483647, ft_is_prime(2147483647));
	printf("%d -> %d\n", 4, ft_is_prime(4));
	printf("%d -> %d\n", 15864, ft_is_prime(15864));
    printf("%d -> %d\n", 53753, ft_is_prime(53753));
    printf("%d -> %d\n", 328701, ft_is_prime(328701));
}
*/