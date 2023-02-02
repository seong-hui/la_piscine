/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:10:51 by hylee2            #+#    #+#             */
/*   Updated: 2023/01/14 15:30:50 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	print(int i, int j, int x, int y)
{
	if (j == 0 && i == 0)
		ft_putchar('A');
	else if (i == x - 1 && j == 0)
		ft_putchar('A');
	else if (i == 0 && j == y - 1)
		ft_putchar('C');
	else if (i == x - 1 && j == y - 1)
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
	{
		write (2, "Please enter a valid value!", 28);
		return ;
	}
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if (i == 0 || j == 0 || j == y - 1 || i == x -1)
				print(i, j, x, y);
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
