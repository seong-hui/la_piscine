/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:40:06 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/30 21:08:51 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	vaild_operator(char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (2);
	else if (c == '*')
		return (3);
	else if (c == '/')
		return (4);
	else if (c == '%')
		return (5);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	m;
	int	re;

	i = 0;
	m = 1;
	re = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = m * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		re = re * 10 + str[i] - '0';
		i++;
	}
	return (re * m);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
