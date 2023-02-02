/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:08:26 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/16 18:22:40 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned long a, unsigned long idx)
{
	char	str[100];
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
	i = 0;
	a += idx;
	while (i < 16)
	{
		str[15 - i] = hex[a % 16];
		a = a / 16;
		i++;
	}
	write (1, str, 16);
	write (1, ":", 1);
}

void	print_str(char *str, int idx, int flag)
{
	int	i;
	int	n;

	i = 0;
	n = 16;
	if (flag != 0)
		n = flag;
	while (i < n)
	{
		if (str[idx + i] >= 32 && str[idx + i] <= 126)
			write(1, &str[idx + i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_hexchar(char *str, int idx, int flag)
{
	char			*hex;
	unsigned char	c;
	int				i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		c = str[idx + i];
		write(1, &hex[c / 16], 1);
		write(1, &hex[c % 16], 1);
		i++;
		while (flag != 0 && i >= flag && i < 16)
		{
			if (i % 2 == 0)
				write(1, " ", 1);
			write(1, "  ", 2);
			i++;
		}
	}
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				flag;

	flag = 0;
	i = 0;
	while (i < size)
	{
		if ((size - i) / 16 == 0)
			flag = (size - i) % 16;
		print_hex((unsigned long)addr, (unsigned long)i);
		print_hexchar((char *)addr, i, flag);
		write(1, " ", 1);
		print_str((char *)addr, i, flag);
		write(1, "\n", 1);
		i += 16;
	}
}

/*
#include <stdio.h>
int main()
{
	char	c12[] = "Bonjour les aminches\t\n\tc  
	est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	
	ft_print_memory((void *)c12, sizeof(c12));
}*/