/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:06:28 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/31 02:14:15 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ascend(int *tab, int i, int (*f)(int, int), int length)
{
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0 || f(tab[i], tab[i + 1]) == 0)
			i++;
		else
			return (0);
	}
	return (1);
}

int	descend(int *tab, int i, int (*f)(int, int), int length)
{
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0 || f(tab[i], tab[i + 1]) == 0)
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (descend(tab, i, f, length));
		else if (f(tab[i], tab[i + 1]) < 0)
			return (ascend(tab, i, f, length));
		i++;
	}
	return (1);
}

/*
int	ft_strcmp(int s1, int s2)
{
	int	i;

	i = 0;
	if (s1 > s2)
			return (s1 - s2);
	else if (s1 < s2)
			return (s1 - s2);
	else
	return (0);
}
#include <stdio.h>
int main()
{
	int (*f)(int a, int b );

	f = ft_strcmp;
	int arr[20] = {1,2, 2, 2, 3, 3, 4, 5, 6, 6, 6, 7};
	printf("%d\n", ft_is_sort(arr, 12, f));
}
*/