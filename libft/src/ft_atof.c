/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:27:20 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/26 17:53:38 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	get_sign(const char *str, int *i, int *point, double *result)
{
	double	sign;

	*point = 0;
	*result = 0.0;
	*i = 0;
	sign = 1.0;
	while (str[*i] == '\n' || str[*i] == '\t' || str[*i] == '\r' \
			|| str[*i] == ' ' || str[*i] == '\v' || str[*i] == '\f')
		(*i)++;
	if (str[*i] == '-')
	{
		(*i)++;
		sign = -1;
	}
	return (sign);
}

double	ft_atof(const char *str)
{
	double		result;
	double		sign;
	int			point;
	int			i;

	sign = get_sign(str, &i, &point, &result);
	while (str[i] != '\0')
	{
		if (str[i] == '.' && !point)
		{
			point = 1;
			i++;
			continue ;
		}
		if (ft_isdigit(str[i]))
		{
			if (point)
				sign /= 10.0;
			result = result * 10.0 + (str[i] - '0');
			i++;
		}
		else
			break ;
	}
	return (result * sign);
}
