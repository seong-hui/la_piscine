/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:02:36 by seonghmo          #+#    #+#             */
/*   Updated: 2023/02/02 04:12:35 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strdup(char *src, int ten_count)
{
	int		i;
	char	*copy_str;

	i = 0;
	copy_str = (char *)malloc(((10 * ten_count) + 1) * sizeof(char));
	if (!copy_str)
		return (0);
	while (src[i] != '\0')
	{
		copy_str[i] = src[i];
		i++;
	}
	copy_str[i] = '\0';
	return (copy_str);
}
