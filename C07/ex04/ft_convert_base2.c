/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:27:35 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/26 01:32:47 by seonghmo         ###   ########.fr       */
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
			*m = (*m) * -1;
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

int	ft_atoi_base(char *nbr, char *base_from)
{
	long long	re;
	int			m;
	int			i;
	int			base_len;

	m = 1;
	re = 0;
	base_len = vaild_base(base_from);
	nbr = first_atoi(nbr);
	nbr = minus(nbr, &m);
	i = 0;
	while (nbr[i])
	{
		if (atoi_check(nbr[i], base_from) >= 0)
			re = (re * base_len) + atoi_check(nbr[i], base_from);
		else
			break ;
		i++;
	}
	return (re * m);
}
