/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:16:32 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/12 20:35:01 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_closest		closest_intersection(t_vector cam, t_vector ray, t_figure figure, double t_min, double t_max)
{
	int			j;
	t_closest	closest;
	t_roots		t;

	closest.t = T_MAX;
	closest.figure = -1;
	j = 0;
	while (j < figure.planes)
	{
		t = plane_intersect(cam, ray, figure.plane[j]);
		if (t.t1 < closest.t && (t.t1 < t_max && t.t1 > t_min))
		{
			closest.t = t.t1;
			closest.figure = j;
			closest.type = 2;		
		}
		if (t.t2 < closest.t && (t.t2 < t_max && t.t2 > t_min))
		{
			closest.t = t.t2;
			closest.figure = j;
			closest.type = 2;
		}
		j++;
	}
	// j = 0;
	// while (j < figure.spheres)
	// {
	// 	t = sphere_intersect(cam, ray, figure.sphere[j]);
	// 	if (t.t1 < closest.t && (t.t1 < t_max && t.t1 > t_min))
	// 	{
	// 		closest.t = t.t1;
	// 		closest.figure = j;
	// 		closest.type = 1;
	// 	}
	// 	if (t.t2 < closest.t && (t.t2 < t_max && t.t2 > t_min))
	// 	{
	// 		closest.t = t.t2;
	// 		closest.figure = j;
	// 		closest.type = 1;
	// 	}
	// 	j++;
	// }
	return (closest);
}

int			raytrace(t_vector cam, t_vector ray, t_figure figure, t_window *win, t_light *light, double t_min, double t_max, int depth)
{
	t_closest	closest;
	int			color;
	int			reflected_color;
	double		intensity;
	double		r;
	t_vector	point;
	t_vector	normal;
	t_vector	reflect;

	closest = closest_intersection(cam, ray, figure, t_min, t_max);
	if (closest.figure == -1)
	{
		color = 0x000000;
		return (color);
	}
	if (closest.type == 1)
	{	
		point = add_vect(cam, num_mult_vec(closest.t, ray));
		normal = get_normal(sub_vect(point, figure.sphere[closest.figure].center));
		intensity = compute_light(point, normal, num_mult_vec(-1, ray), light, win, figure.sphere[closest.figure].shine, figure);
		color = get_color(figure.sphere[closest.figure].color, figure.sphere[closest.figure].color, intensity, 1);
		r = figure.sphere[closest.figure].reflect;
		if (depth <= 0 || r <= 0)
			return (color);
		reflect = reflect_ray(normal, num_mult_vec(-1, ray));
		reflected_color = raytrace(point, reflect, figure, win, light, 0.001, T_MAX, depth - 1);
		color = get_color(get_color(color, color, 1 - r, 1), get_color(reflected_color, color, r, 1), 1, 2);
	}
	else
		color = figure.plane[closest.figure].color;
	return (color);
}

void		draw_figure(t_window *win, t_vector cam, t_figure figure, t_light *light)
{
	t_vector	ray;
	int			x;
	int			y;
	int			color;

	y = -(WIN_H / 2);
	while (y < (WIN_H / 2))
	{
		x = -(WIN_W / 2);
		while (x < (WIN_W / 2))
		{
			ray = get_viewport(x, y);
			color = raytrace(cam, ray, figure, win, light, T_MIN, T_MAX, win->recursion_depth);
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, WIN_W / 2 + x, WIN_H / 2 - y - 1, color);
			x++;
		}
		y++;
	}	
}
