/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:16:39 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/30 00:20:12 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{

	}
	else if (ac == 1)
	{
		write(1, "File name missing.\n", 19);
		return (0);
	}
	else if (ac >= 3)
	{
		write(1, "Too many argument\n", 18);
		return (0);
	}
	else
	{

	}
}