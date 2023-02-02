/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:15:08 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/16 01:09:13 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*white_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v')
			i++;
		else if (str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
		else
			break ;
	}
	return (&str[i]);
}

char	*minus(char *str, int *m)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			*m = -*m;
			i++;
		}
		else if (str[i] == '+')
			i++;
		else
			break ;
	}
	return (&str[i]);
}

int	ft_atoi(char *str)
{
	int	i;
	int	m;
	int	re;

	i = 0;
	m = 1;
	re = 0;
	str = white_space(str);
	str = minus(str, &m);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			re = re * 10 + (str[i] - '0');
			i++;
		}
		else
			break ;
	}
	return (m * re);
}

/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi( "		 ---+--+1234ab567"));
}*/