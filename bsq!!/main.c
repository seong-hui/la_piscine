/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:49:40 by seonghmo          #+#    #+#             */
/*   Updated: 2023/02/02 04:25:07 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	first_map_len(char *p)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (p[i])
	{
		if (p[i] == '\n')
			break ;
		i++;
		len++;
	}
	return (len);
}

char	*open_and_read(char *av)
{	
	int		fd;
	char	buff;
	int		len;
	char	*p;

	len = 0;
	fd = open(av, O_RDONLY);
	if (0 < fd)
	{
		while (0 < read(fd, &buff, 1))
			len++;
	}
	else if (open_error() == -1)
		return (0);
	close(fd);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (0);
	fd = open(av, O_RDONLY);
	read(fd, p, len);
	p[len] = '\0';
	close(fd);
	return (p);
}

char	*read_input(void)
{
	char	*p;
	int		i;
	char	buff;

	p = (char *)malloc(((10 * 1) + 1) * sizeof(char));
	if (!p)
		return (0);
	i = 0;
	while (0 < read(0, &buff, 1))
	{
		p[i++] = buff;
		if (i == (i / 10) * 10)
		{
			p[i] = '\0';
			p = ft_strdup(p, (i / 10 + 1));
			if (!p)
				return (0);
		}
	}
	if (!p)
		return (0);
	p[i] = '\0';
	return (p);
}

void	ft_read(void)
{
	t_map_info	info;
	char		*p;
	char		**map;

	p = read_input();
	if (!p)
		write(2, "map error\n", 10);
	else
	{
		if (map_info(p, &info) == -1)
			write(2, "map error\n", 10);
		else
		{
			map = split_line(p, info);
			if (!map)
				write(2, "map error\n", 10);
			else
				sample(map, info);
		}
	}
}	

int	main(int ac, char **av)
{
	int			i;
	char		*p;
	char		**map;
	t_map_info	info;

	i = 0;
	if (ac == 1)
		ft_read();
	while (++i < ac)
	{
		p = open_and_read(av[i]);
		if (!p)
			continue ;
		if (map_info(p, &info) == -1)
			write(2, "map error\n", 10);
		else
		{
			map = split_line(p, info);
			if (!map)
				write(2, "map error\n", 10);
			else
				sample(map, info);
		}
	}
	return (0);
}
