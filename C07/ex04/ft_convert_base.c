/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:05:04 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/26 01:32:56 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		vaild_base(char *base);
void	itoa(long long n, char *p, int len, char *base);
int		ft_atoi_base(char *nbr, char *base_from);

int	ft_len(long long n, int base_len)
{
	int	i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n > base_len - 1)
	{
		i++;
		n = n / base_len;
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	n;
	int			len;
	char		*p;
	int			base_len;
	int			base_len2;

	base_len = vaild_base(base_from);
	base_len2 = vaild_base(base_to);
	if (base_len == 0 || base_len == 1 || base_len2 == 0 || base_len2 == 1)
		return (0);
	n = ft_atoi_base(nbr, base_from);
	len = ft_len(n, base_len2);
	if (n < 0)
	{
		p = (char *)malloc(sizeof(char) * len + 2);
		p[0] = '-';
		len++;
		n = -n;
	}
	else
		p = (char *)malloc(sizeof(char) * len + 1);
	len--;
	itoa(n, p, len, base_to);
	p[len + 1] = '\0';
	return (p);
}

void	itoa(long long n, char *p, int len, char *base)
{
	int	base_len;

	base_len = vaild_base(base);
	if (n > base_len - 1)
		itoa(n / base_len, p, len - 1, base);
	p[len] = base[n % base_len];
}

/*
#include <stdio.h>
int main()
{
	char base1[100] ="0123456789";
	char base2[100] = "01234567";

	printf("%s\n", ft_convert_base("   ----+-++1234a ", base1, base2));
	printf("%s\n", ft_convert_base("---af", "0123456789abcdef", "01"));
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", 
	"0123456789abcdef"));
	printf("%s\n", ft_convert_base("  +0", "0123456789", "0123456789"));
	printf("%s\n", ft_convert_base("-7", "0123456789", "0123456"));
	printf("%s\n", ft_convert_base("   +--+-2132 56", "0123456789" ,"0123456"));
}*/