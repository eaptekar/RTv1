/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 20:31:51 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/15 20:32:12 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	reflect_ray(t_vector normal, t_vector ray)
{
	t_vector	reflect;

	reflect = sub_vect(num_mult_vec(2 * scal_prod(normal, ray), normal), ray);
	return (reflect);
}

int			get_color(int color, int reflect_color, double intensity, int state)
{
	int		red;
	int		green;
	int		blue;

	if (state == 1)
	{
		red = (fmin(255, round((color & 0xFF0000) >> 16) * intensity));
		green = (fmin(255, round((color & 0xFF00) >> 8) * intensity));
		blue = (fmin(255, round((color & 0xFF)) * intensity));
	}
	//state == 2
	else
	{
		red = (fmin(255, ((color & 0xFF0000) >> 16) + ((reflect_color & 0xFF0000) >> 16)));
		green = (fmin(255, ((color & 0xFF00) >> 8) + ((reflect_color & 0xFF00) >> 8)));
		blue = (fmin(255, (color & 0xFF) + (reflect_color & 0xFF)));
	}
	color = blue | (green << 8) | (red << 16);
	return (color);
}