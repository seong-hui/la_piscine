/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:56:18 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/30 23:20:52 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*p;

	p = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		p[i] = f(tab[i]);
		i++;
	}
	return (p);
}
