/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:22:48 by seonghmo          #+#    #+#             */
/*   Updated: 2023/02/02 04:14:33 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	open_error(void)
{
	write(2, "map error\n", 10);
	return (-1);
}

int	is_not_same(char emtpy, char obstacle, char full)
{
	if (emtpy != obstacle && obstacle != full && full != emtpy)
		return (0);
	return (1);
}

void	ft_free(char **map, int **board, t_map_info info)
{
	int	i;

	i = 0;
	while (i < info.row + 1)
	{
		free(board[i]);
		i++;
	}
	free(board);
	i = 0;
	while (i < info.row)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
