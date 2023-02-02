/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:08:49 by seonghmo          #+#    #+#             */
/*   Updated: 2023/01/16 00:19:21 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
			str[0] -= + 'a' - 'A';
	while (str[i])
	{
		if (!(str[i - 1] >= 'a' && str[i - 1] <= 'z')
			&& !(str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			&& !(str[i - 1] >= '0' && str[i - 1] <= '9'))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 'a' - 'A';
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 'a' - 'A';
		}
		i++;
	}
	return (str);
}

/*
#include <stdio.h>
int main()
{
	char str[] = "42Mod";
	ft_strcapitalize(str);

	printf("%s", str);
}*/