/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:17:49 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/14 17:02:13 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap (&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

/*
#include <stdio.h>
int main()
{
	int tab[] = {9,8,1,3,2};
	ft_sort_int_tab(tab, 5);
	for(int i=0;i<5;i++)
	{
		printf("%d ", tab[i]);
	}
	
}
*/