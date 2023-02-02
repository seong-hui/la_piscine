/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:45:30 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/25 22:17:12 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*p;
	int	i;

	i = 0;
	if (max <= min)
		return (0);
	else
	{
		p = (int *)malloc(sizeof(int) * (max - min));
		while (min < max)
		{
			p[i] = min;
			i++;
			min++;
		}
	}
	return (p);
}
/*
#include <stdio.h>
int main()
{
	int *a = NULL;

	a = ft_range(4, 10);
	for(int i = 0; i < 6;i++)
		printf("%d ", a[i]);

}*/