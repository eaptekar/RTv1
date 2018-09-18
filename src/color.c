/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 20:31:51 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/18 18:42:55 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_figure	cylinder(t_scene scene, t_vector cam, \
	t_vector ray, t_closest closest)
{
	t_figure	f;
	double		m;

	m = dot(ray, scene.cylinder[closest.i].axis) * closest.t + dot(sub(cam, \
		scene.cylinder[closest.i].center), scene.cylinder[closest.i].axis);
	f.point = add(cam, mult(closest.t, ray));
	f.normal = get_normal(sub(sub(f.point, scene.cylinder[closest.i].center), \
		mult(m, scene.cylinder[closest.i].axis)));
	f.shine = scene.cylinder[closest.i].shine;
	f.color = scene.cylinder[closest.i].color;
	f.r = scene.cylinder[closest.i].reflect;
	return (f);
}

t_figure	cone(t_scene scene, t_vector cam, t_vector ray, t_closest closest)
{
	t_figure	f;
	double		m;
	double		a;

	m = dot(ray, scene.cone[closest.i].axis) * closest.t + dot(sub(cam, \
		scene.cone[closest.i].center), scene.cone[closest.i].axis);
	a = m * scene.cone[closest.i].k * scene.cone[closest.i].k;
	f.point = add(cam, mult(closest.t, ray));
	f.normal = get_normal(sub(sub(f.point, scene.cone[closest.i].center), \
		mult((1 + scene.cone[closest.i].k * scene.cone[closest.i].k), \
			mult(m, scene.cone[closest.i].axis))));
	f.shine = scene.cone[closest.i].shine;
	f.color = scene.cone[closest.i].color;
	f.r = scene.cone[closest.i].reflect;
	return (f);
}

t_figure	closest_figure(t_scene scene, t_vector cam, \
	t_vector ray, t_closest closest)
{
	t_figure	f;

	if (closest.type == 1)
	{
		f.point = add(cam, mult(closest.t, ray));
		f.normal = scene.plane[closest.i].normal;
		f.shine = scene.plane[closest.i].shine;
		f.color = scene.plane[closest.i].color;
		f.r = scene.plane[closest.i].reflect;
	}
	else if (closest.type == 2)
	{
		f.point = add(cam, mult(closest.t, ray));
		f.normal = get_normal(sub(f.point, scene.sphere[closest.i].center));
		f.shine = scene.sphere[closest.i].shine;
		f.color = scene.sphere[closest.i].color;
		f.r = scene.sphere[closest.i].reflect;
	}
	else if (closest.type == 3)
		f = cylinder(scene, cam, ray, closest);
	else
		f = cone(scene, cam, ray, closest);
	return (f);
}

t_vector	reflect_ray(t_vector normal, t_vector ray)
{
	t_vector	reflect;

	reflect = sub(mult(2 * dot(normal, ray), normal), ray);
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
	else
	{
		red = (fmin(255, ((color & 0xFF0000) >> 16) + \
			((reflect_color & 0xFF0000) >> 16)));
		green = (fmin(255, ((color & 0xFF00) >> 8) + \
			((reflect_color & 0xFF00) >> 8)));
		blue = (fmin(255, (color & 0xFF) + (reflect_color & 0xFF)));
	}
	color = blue | (green << 8) | (red << 16);
	return (color);
}
