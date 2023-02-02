/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:35:07 by minsokan          #+#    #+#             */
/*   Updated: 2023/02/02 04:12:40 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	put_oper(char *p, t_map_info *info, int len)
{
	info->full = p[len - 1];
	info->obstacle = p[len - 2];
	info->empty = p[len - 3];
}

char	**split_line(char *p, t_map_info info)
{
	int		i;
	char	**map;

	i = 0;
	while (p[i] != '\n')
		i++;
	map = ft_split(p + i, "\n", info);
	free (p);
	if (!map)
		return (0);
	return (map);
}

int	map_info(char *p, t_map_info *info)
{
	char	*input_row;
	int		len;

	len = first_map_len(p);
	if (len < 4)
		return (-1);
	put_oper(p, info, len);
	if (is_not_same(info->empty, info->obstacle, info->full))
		return (-1);
	input_row = (char *)malloc(sizeof(char) * (len - 2));
	if (!input_row)
		return (-1);
	if (cal_low(p, input_row, len, info) == 0)
		return (-1);
	if (cal_col(p, len, info) == 0)
		return (-1);
	free(input_row);
	return (0);
}

int	cal_low(char *p, char *input_row, int len, t_map_info *info)
{
	int	i;
	int	col;
	int	n_cnt;

	i = 0;
	n_cnt = 0;
	col = 0;
	while (i < len - 3)
	{
		input_row[i] = p[i];
		i++;
	}
	input_row[i] = '\0';
	while (p[len])
	{
		if (p[len] == '\n')
			n_cnt++;
		len++;
	}
	info->row = ft_atoi(input_row);
	if (info->row != n_cnt - 1)
		return (0);
	if (info->row <= 0 || info->row > 2147483647)
		return (0);
	return (1);
}

int	cal_col(char *p, int len, t_map_info *info)
{
	int	i;
	int	col;

	i = 0;
	col = 0;
	while (p[++len] != '\n')
		col++;
	info->col = col;
	if (info->col <= 0)
		return (0);
	return (1);
}
