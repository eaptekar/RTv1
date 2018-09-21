/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:10:48 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/21 16:34:14 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_closest	closest_intersection(t_vector cam, t_vector ray, t_scene scene)
{
	int			i;
	t_closest	closest;
	t_roots		t;

	i = 0;
	closest.t = T_MAX;
	closest.type = 0;
	while (i < scene.figures)
	{
		t = get_roots(i, scene, cam, ray);
		if (t.t1 < closest.t && (t.t1 < scene.t_max && t.t1 > scene.t_min))
		{
			closest.t = t.t1;
			closest.i = t.i;
			closest.type = t.type;
		}
		if (t.t2 < closest.t && (t.t2 < scene.t_max && t.t2 > scene.t_min))
		{
			closest.t = t.t2;
			closest.i = t.i;
			closest.type = t.type;
		}
		i++;
	}
	return (closest);
}

double		get_intensity(t_figure f, t_scene scene, t_vector l_dir, int i)
{
	double		intensity;
	t_closest	closest;
	t_vector	reflect;

	intensity = 0.0;
	if (scene.light[i].type == 1)
		return (scene.light[i].intensity);
	scene.t_min = 0.001;
	closest = closest_intersection(f.point, l_dir, scene);
	if (closest.type == 0)
	{
		if (dot(f.normal, l_dir) > 0)
			intensity += ((scene.light[i].intensity * dot(f.normal, l_dir)) / \
				(sqrt(dot(f.normal, f.normal)) * sqrt(dot(l_dir, l_dir))));
		if (f.shine != -1)
		{
			reflect = reflect_ray(f.normal, l_dir);
			if (dot(reflect, f.ray) > 0)
				intensity += scene.light[i].intensity * \
			pow(dot(reflect, f.ray) / (sqrt(dot(reflect, reflect)) * \
				sqrt(dot(f.ray, f.ray))), f.shine);
		}
	}
	return (intensity);
}

double		compute_light(t_figure f, t_vector ray, t_scene scene)
{
	double		intensity;
	int			i;
	t_vector	l_dir;

	intensity = 0.0;
	i = 0;
	f.ray = ray;
	while (i < scene.sources)
	{
		if (scene.light[i].type == 2)
		{
			l_dir = sub(scene.light[i].ray, f.point);
			scene.t_max = 1.0;
		}
		else if (scene.light[i].type == 3)
		{
			l_dir = scene.light[i].ray;
			scene.t_max = T_MAX;
		}
		intensity += get_intensity(f, scene, l_dir, i);
		i++;
	}
	return (intensity);
}

int			raytrace(t_vector cam, t_vector ray, t_scene scene, int depth)
{
	t_closest	closest;
	t_vector	reflect;
	t_figure	f;
	int			color;
	int			reflected_color;

	closest = closest_intersection(cam, ray, scene);
	if (closest.type == 0)
	{
		color = 0x000000;
		return (color);
	}
	f = closest_figure(scene, cam, ray, closest);
	color = get_color(f.color, 0, compute_light(f, mult(-1, ray), scene), 1);
	if (depth <= 0 || f.r <= 0)
		return (color);
	reflect = reflect_ray(f.normal, mult(-1, ray));
	scene.t_min = 0.001;
	reflected_color = raytrace(f.point, reflect, scene, depth - 1);
	color = get_color(get_color(color, 0, 1 - f.r, 1), \
		get_color(reflected_color, 0, f.r, 1), 1, 2);
	return (color);
}

void		draw_scene(t_window *win, t_scene scene)
{
	t_vector	ray;
	int			x;
	int			y;
	int			color;

	scene.t_min = T_MIN;
	scene.t_max = T_MAX;
	y = -(WIN_H / 2);
	while (y < (WIN_H / 2))
	{
		x = -(WIN_W / 2);
		while (x < (WIN_W / 2))
		{
			ray = rotate_camera(get_viewport(x, y), scene.angle);
			color = raytrace(scene.cam, ray, scene, scene.recursion_depth);
			pixel_to_image(win, WIN_W / 2 + x, WIN_H / 2 - y, color);
			x++;
		}
		y++;
	}
}
