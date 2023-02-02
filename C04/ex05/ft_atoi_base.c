/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:05:30 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/23 11:59:45 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	vaild_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+'
			|| base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

char	*first_atoi(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
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

int	atoi_check(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			base_len;
	int			re;
	int			m;
	int			i;

	m = 1;
	re = 0;
	base_len = vaild_base(base);
	if (base_len == 0 || base_len == 1)
		return (0);
	str = first_atoi(str);
	str = minus(str, &m);
	i = 0;
	while (str[i])
	{
		if (atoi_check(str[i], base) >= 0)
			re = (re * base_len) + atoi_check(str[i], base);
		else
			break ;
		i++;
	}
	return (re * m);
}

/*
#include <stdio.h>
int main()
{
	int n;

	n = ft_atoi_base("   ----+-44", "0123456789");
	printf("%d", n);
}*/