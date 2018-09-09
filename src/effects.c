/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 14:43:09 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/09 18:34:42 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		compute_light(t_vector point, t_vector normal, t_vector ray, t_light *light, int sources, int shine)
{
	double		intensity;
	int			i;
	t_vector	l_dir;
	t_vector	reflect;

	intensity = 0.0;
	i = 0;
	while (i < sources)
	{
		if (light[i].type == 1)
			intensity += light[i].intensity;
		else
		{
			if (light[i].type == 2)
				l_dir = sub_vect(light[i].ray, point);
			else
				l_dir = light[i].ray;
			if (scal_prod(normal, l_dir) > 0)
				intensity += ((light[i].intensity * scal_prod(normal, l_dir)) / (sqrt(scal_prod(normal, normal)) * sqrt(scal_prod(l_dir, l_dir))));
			if (shine != -1)
			{
				reflect = sub_vect(num_mult_vec(2 * scal_prod(normal, l_dir), normal), l_dir);
				if (scal_prod(reflect, ray) > 0)
					intensity += light[i].intensity * pow(scal_prod(reflect, ray) / (sqrt(scal_prod(reflect, reflect)) * sqrt(scal_prod(ray, ray))), shine);
			}
		}
		i++;
	}
	return (intensity);
}

int			get_color(int color, double intensity)
{
	int		red;
	int		green;
	int		blue;

	red = (fmin(255, round((color & 0xFF0000) >> 16) * intensity));
	green = (fmin(255, round((color & 0xFF00) >> 8) * intensity));
	blue = (fmin(255, round((color & 0xFF)) * intensity));
	color = blue | (green << 8) | (red << 16);
	return (color);
}