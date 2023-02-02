/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:54:20 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/30 21:09:11 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	vaild_operator(char c);
int	ft_atoi(char *str);
int	plus(int a, int b);
int	minus(int a, int b);
int	multiply(int a, int b);
int	divide(int a, int b);
int	ft_remainder(int a, int b);
int	ft_strlen(char *str);

int	cal(int a, int b, char oper)
{
	int	(*p[6])(int, int);

	p[1] = plus;
	p[2] = minus;
	p[3] = multiply;
	p[4] = divide;
	p[5] = ft_remainder;
	if (vaild_operator(oper) == 1)
		return (p[1](a, b));
	else if (vaild_operator(oper) == 2)
		return (p[2](a, b));
	else if (vaild_operator(oper) == 3)
		return (p[3](a, b));
	else if (vaild_operator(oper) == 4)
		return (p[4](a, b));
	else
		return (p[5](a, b));
}

void	ft_putnbr(int nb)
{
	long long	n;
	char		c;

	n = nb;
	if (n < 0)
	{
		write (1, "-", 1);
		n = n * (-1);
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	a;
	int	b;

	if (ac == 4)
	{
		a = ft_atoi(av[1]);
		b = ft_atoi(av[3]);
		if (ft_strlen(av[2]) != 1 || vaild_operator(av[2][0]) == 0)
			write(1, "0", 1);
		else if (b == 0 && vaild_operator(av[2][0]) == 4)
			write(1, "Stop : division by zero", 23);
		else if (b == 0 && vaild_operator(av[2][0]) == 5)
			write(1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(cal(a, b, av[2][0]));
		write(1, "\n", 1);
	}
	return (0);
}
