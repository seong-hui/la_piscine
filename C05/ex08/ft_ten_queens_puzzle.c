/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:55:25 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/22 14:33:07 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	possible_queen(char *str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (str[i] == str[index])
			return (0);
		else if (index - i == str[i] - str[index]
			|| index - i == - (str[i] - str[index]))
			return (0);
		i++;
	}
	return (1);
}

void	recul(char *str, int index, int *cnt)
{
	int	input;

	if (index == 10)
	{
		write(1, str, 10);
		write(1, "\n", 1);
		*cnt = *cnt + 1;
		return ;
	}
	else
	{
		input = 0;
		while (input <= 9)
		{
			str[index] = input + '0';
			if (possible_queen(str, index))
				recul(str, index + 1, cnt);
			input ++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	str[10];
	int		cnt;

	cnt = 0;
	recul(str, 0, &cnt);
	return (cnt);
}

/*
#include <stdio.h>

int main()
{
	printf("%d", ft_ten_queens_puzzle());
	
}*/