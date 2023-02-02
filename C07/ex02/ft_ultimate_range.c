/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:37:01 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/25 22:17:42 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	n;

	i = 0;
	if (max <= min)
	{
		*range = 0;
		return (0);
	}
	else
	{
		n = min;
		range[0] = (int *)malloc(sizeof(int) * (max - min));
		if (!(*range))
			return (-1);
		while (n < max)
		{
			range[0][i] = n;
			n++;
			i++;
		}
	}
	return (max - min);
}

/*
#include <stdio.h>
int	main()
{
printf("\n--ex02--\n\n");

	int	*arr2;
	int	min2;
	int max2;

	min2 = -6;
	max2 = 5;
	int i = 0;
	ft_ultimate_range(&arr2, min2, max2);
	while (min2 < max2)
	{
		printf("%d\n", arr2[i++]);
		min2++;
	}
}
*/