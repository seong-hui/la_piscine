/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:52:17 by seonghmo          #+#    #+#             */
/*   Updated: 2023/02/02 04:16:18 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map_info
{
	int		row;
	int		col;
	char	empty;
	char	obstacle;
	char	full;
}	t_map_info;

int		sample(char **map, t_map_info info);
char	**ft_split(char *str, char *charset, t_map_info info);
int		ft_atoi(char *str);
void	ft_read(void);
char	*ft_strdup(char *src, int ten_count);
void	put_oper(char *p, t_map_info *info, int len);
int		cal_low(char *p, char *input_row, int len, t_map_info *info);
int		cal_col(char *p, int len, t_map_info *info);
int		is_not_same(char emtpy, char obstacle, char full);
int		open_error(void);
void	ft_free(char **map, int **board, t_map_info info);
char	**split_line(char *p, t_map_info info);
int		map_info(char *p, t_map_info *info);
int		first_map_len(char *p);
#endif
