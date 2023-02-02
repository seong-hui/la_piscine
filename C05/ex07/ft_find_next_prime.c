/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:17:15 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/22 14:33:38 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	i;

	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i ++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
}

/*
#include <stdio.h>
int main()
{
	printf("%d -> %d\n", -398, ft_find_next_prime(-398));
    printf("%d -> %d\n", 0, ft_find_next_prime(0));
    printf("%d -> %d\n", 1, ft_find_next_prime(1));
    printf("%d -> %d\n", 2, ft_find_next_prime(2));
	printf("%d -> %d\n", 4, ft_find_next_prime(2));
    printf("%d -> %d\n", 7853, ft_find_next_prime(7853));
    printf("%d -> %d\n", 78989, ft_find_next_prime(78989));
    printf("%d -> %d\n", 2147483643, ft_find_next_prime(2147483640));
    printf("%d -> %d\n", 2147483645, ft_find_next_prime(2147483645));
    printf("%d -> %d\n", 2147483646, ft_find_next_prime(2147483646));
    printf("%d -> %d\n", 2147483647, ft_find_next_prime(2147483647));
    printf("%d -> %d\n", 307201, ft_find_next_prime(307201));
    printf("%d -> %d\n", 263692, ft_find_next_prime(263692));
    printf("%d -> %d\n", 83477, ft_find_next_prime(83477));
    printf("%d -> %d\n", 199709, ft_find_next_prime(199709));
    printf("%d -> %d\n", 287272, ft_find_next_prime(287272));

}*/