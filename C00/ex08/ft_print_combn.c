/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:40:04 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/14 20:32:34 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *str, int n, int index, int input)
{
	if (index == n)
	{
		write (1, str, n);
		if (str[0] != 10 - n + '0')
			write (1, ", ", 2);
		return;
	}
	else
	{
		while (input <= 9)
		{
			str[index] = input + '0';
			print(str, n, index + 1, input + 1);
			input++;
		}	
	}
}

void	ft_print_combn(int n)
{
	char	str[9];

	print(str, n, 0, 0);
}
