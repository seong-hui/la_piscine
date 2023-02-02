/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:58:48 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/14 16:59:59 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp[100];
	int	i;

	i = 0;
	size--;
	while (size >= 0)
	{
		tmp[i] = tab[i];
		i++;
		size--;
	}
	size++;
	i--;
	while (i >= 0)
	{
		tab[size++] = tmp[i--];
	}
}

/*
#include <stdio.h>
int main()
{
	int a[] = {0,};
	ft_rev_int_tab(a, 0);
	for(int i = 0;i<6;i++)
	{
		printf("%d", a[i]);
	}
}
*/