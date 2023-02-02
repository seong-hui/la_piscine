/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:59:37 by minsokan          #+#    #+#             */
/*   Updated: 2023/02/02 04:12:38 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	three_min(int x, int y, int z)
{
	int	min;

	min = x;
	if (min > y)
		min = y;
	if (min > z)
		min = z;
	return (min);
}

void	solve(int **board, t_map_info info, int max[3])
{
	int	i;
	int	j;

	max[0] = 0;
	i = 1;
	while (i < info.row + 1)
	{
		j = 1;
		while (j < info.col + 1)
		{
			if (board[i][j] >= 1)
			{
				board[i][j] = three_min(board[i - 1][j - 1],
						board[i - 1][j], board[i][j - 1]) + 1;
				if (max[0] < board[i][j])
				{
					max[0] = board[i][j];
					max[1] = i - 1;
					max[2] = j - 1;
				}
			}
			j++;
		}
		i++;
	}
}

void	change(int **board, char **map, t_map_info info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.row + 1)
	{
		j = 0;
		while (j < info.col + 1)
		{
			if (i == 0 || j == 0)
			{
				board[i][j++] = 0;
				continue ;
			}
			if (map[i - 1][j - 1] == info.empty)
				board[i][j] = 1;
			else if (map[i - 1][j - 1] == info.obstacle)
				board[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_ans(char **map, t_map_info info, int max[3])
{
	int	i;
	int	j;

	i = max[1] - max[0];
	while (++i <= max[1])
	{
		j = max[2] - max[0];
		while (++j <= max[2])
			map[i][j] = info.full;
	}
	i = 0;
	while (i < info.row)
	{
		j = 0;
		while (j < info.col)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	sample(char **map, t_map_info info)
{
	int	**board;
	int	max[3];
	int	i;

	board = (int **)malloc((info.row + 1) * sizeof(int *));
	if (board == NULL)
		return (0);
	i = 0;
	while (i < info.row + 1)
	{
		board[i] = (int *)malloc((info.col + 1) * sizeof(int));
		if (board[i] == NULL)
			return (0);
		i++;
	}
	change(board, map, info);
	solve(board, info, max);
	print_ans(map, info, max);
	write(1, "\n", 1);
	ft_free(map, board, info);
	return (0);
}
