/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscolor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:28:21 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/08 19:46:25 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iscolor(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
	{
		i += 2;
		while (str[i])
		{
			if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' \
				&& str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F'))
				i++;
			else
				return (0);
		}
	}
	if (i != 8)
		return (0);
	return (1);
}
