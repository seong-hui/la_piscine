/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:15:37 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/16 12:58:09 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	int				a;
	int				b;
	char			*hex;
	unsigned char	c;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		c = str[i];
		if (!(c >= 32 && c <= 126))
		{
			write(1, "\\", 1);
			b = c / 16;
			write(1, &hex[b], 1);
			a = c % 16;
			write(1, &hex[a], 1);
		}
		else
			write(1, &c, 1);
		i++;
	}
}

/*
#include <stdio.h>

int main()
{
	//ft_putstr_non_printable("Coucou\ntu vas bien ?");
	printf("< ex11 >\n");
	printf("-----------answer------------\n");
	printf("Coucou\\0atu vas bien ?\n");
	printf("\\c8\\7f\n");
	printf("-------------------------------\n");
	ft_putstr_non_printable("Concou\ntu vas bien ?");
	write(1, "\n", 1);
	char aa[3] = { 200, 127, 0};
	ft_putstr_non_printable(aa);
	printf("\n");
	printf("-----------output------------\n\n");
}*/