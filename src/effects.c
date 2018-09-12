/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 14:43:09 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/12 20:23:05 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	reflect_ray(t_vector normal, t_vector ray)
{
	t_vector	reflect;

	reflect = sub_vect(num_mult_vec(2 * scal_prod(normal, ray), normal), ray);
	return (reflect);
}

double		compute_light(t_vector point, t_vector normal, t_vector ray, t_light *light, t_window *win, int shine, t_figure figure)
{
	double		intensity;
	int			i;
	t_vector	l_dir;
	t_vector	reflect;
	double		t_max;
	t_closest	closest;

	intensity = 0.0;
	i = 0;
	while (i < win->sources)
	{
		if (light[i].type == 1)
			intensity += light[i].intensity;
		else
		{
			if (light[i].type == 2)
			{
				l_dir = sub_vect(light[i].ray, point);
				t_max = 1.0;
			}
			else
			{
				l_dir = light[i].ray;
				t_max = T_MAX;
			}
			closest = closest_intersection(point, l_dir, figure, 0.001, t_max);
			if (closest.figure == -1)
			{
				if (scal_prod(normal, l_dir) > 0)
					intensity += ((light[i].intensity * scal_prod(normal, l_dir)) / (sqrt(scal_prod(normal, normal)) * sqrt(scal_prod(l_dir, l_dir))));
				if (shine != -1)
				{
					reflect = reflect_ray(normal, l_dir);
					if (scal_prod(reflect, ray) > 0)
						intensity += light[i].intensity * pow(scal_prod(reflect, ray) / (sqrt(scal_prod(reflect, reflect)) * sqrt(scal_prod(ray, ray))), shine);
				}
			}
		}
		i++;
	}
	return (intensity);
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
	else
	{
		red = (fmin(255, ((color & 0xFF0000) >> 16) + ((reflect_color & 0xFF0000) >> 16)));
		green = (fmin(255, ((color & 0xFF00) >> 8) + ((reflect_color & 0xFF00) >> 8)));
		blue = (fmin(255, (color & 0xFF) + (reflect_color & 0xFF)));
	}
	color = blue | (green << 8) | (red << 16);
	return (color);
}