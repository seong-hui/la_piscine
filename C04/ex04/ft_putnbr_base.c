/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:09:54 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/19 14:42:44 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	vaild_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
		{
			return (0);
		}
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_len;
	char		c;
	long long	n;

	n = nbr;
	base_len = ft_strlen(base);
	if (base_len == 0 || base_len == 1)
		return ;
	if (vaild_base(base) == 0)
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > base_len - 1)
		ft_putnbr_base(n / base_len, base);
	c = base[n % base_len];
	write(1, &c, 1);
}

/*
int main()
{
	ft_putnbr_base(2 , "01");
}*/