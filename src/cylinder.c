/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:15:06 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/15 22:49:51 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_roots		cyl_intersect(t_vector cam, t_vector ray, t_cylinder c)
{
	double		a;
	double		b;
	double		ci;
	double		discr;
	t_roots		t;

	a = scal_prod(ray, ray) - pow(scal_prod(ray, c.axis), 2);
	b = 2 * (scal_prod(ray, sub_vect(cam, c.center)) - scal_prod(ray, c.axis) * scal_prod(sub_vect(cam, c.center), c.axis));
	ci = scal_prod(sub_vect(cam, c.center), sub_vect(cam, c.center)) - pow(scal_prod(sub_vect(cam, c.center), c.axis), 2) - c.radius * c.radius;
	discr = b * b - 4 * a * ci;
	if (discr < 0)
	{
		t.t1 = T_MAX;
		t.t2 = T_MAX;
		return (t);
	}
	t.t1 = (-b + sqrt(discr)) / (2 * a);
	t.t2 = (-b - sqrt(discr)) / (2 * a);
	return (t);
}

// t_closest		closest_intersection_cyl(t_window *win, t_vector cam, t_vector ray, t_cylinder *c, double t_min, double t_max)
// {
// 	int			i;
// 	t_closest	closest;
// 	t_roots		t;

// 	closest.t = T_MAX;
// 	closest.figure = -1;
// 	i = 0;
// 	while (i < win->figures)
// 	{
// 		t = cyl_intersect(cam, ray, c[i]);
// 		if (t.t1 < closest.t && (t.t1 < t_max && t.t1 > t_min))
// 		{
// 			closest.t = t.t1;
// 			closest.figure = i;
// 		}
// 		if (t.t2 < closest.t && (t.t2 < t_max && t.t2 > t_min))
// 		{
// 			closest.t = t.t2;
// 			closest.figure = i;
// 		}
// 		i++;
// 	}
// 	return (closest);
// }

// double		compute_light_cyl(t_vector point, t_vector normal, t_vector ray, t_light *light, t_window *win, int shine, t_cylinder *c)
// {
// 	double		intensity;
// 	int			i;
// 	t_vector	l_dir;
// 	t_vector	reflect;
// 	double		t_max;
// 	t_closest	closest;

// 	intensity = 0.0;
// 	i = 0;
// 	while (i < win->sources)
// 	{
// 		if (light[i].type == 1)
// 			intensity += light[i].intensity;
// 		else
// 		{
// 			if (light[i].type == 2)
// 			{
// 				l_dir = sub_vect(light[i].ray, point);
// 				t_max = 1.0;
// 			}
// 			else
// 			{
// 				l_dir = light[i].ray;
// 				t_max = T_MAX;
// 			}
// 			closest = closest_intersection_cyl(win, point, l_dir, c, 0.001, t_max);
// 			if (closest.figure == -1)
// 			{
// 				if (scal_prod(normal, l_dir) > 0)
// 					intensity += ((light[i].intensity * scal_prod(normal, l_dir)) / (sqrt(scal_prod(normal, normal)) * sqrt(scal_prod(l_dir, l_dir))));
// 				if (shine != -1)
// 				{
// 					reflect = reflect_ray(normal, l_dir);
// 					if (scal_prod(reflect, ray) > 0)
// 						intensity += light[i].intensity * pow(scal_prod(reflect, ray) / (sqrt(scal_prod(reflect, reflect)) * sqrt(scal_prod(ray, ray))), shine);
// 				}
// 			}
// 		}
// 		i++;
// 	}
// 	return (intensity);
// }

// int			raytrace_cyl(t_vector cam, t_vector ray, t_cylinder *c, t_window *win, t_light *light, double t_min, double t_max, int depth)
// {
// 	t_closest	closest;
// 	int			color;
// 	int			reflected_color;
// 	double		intensity;
// 	double		r;
// 	t_vector	point;
// 	t_vector	normal;
// 	t_vector	reflect;
// 	double		m;

// 	closest = closest_intersection_cyl(win, cam, ray, c, t_min, t_max);
// 	if (closest.figure == -1)
// 	{
// 		color = 0x000000;
// 		return (color);
// 	}
// 	m = scal_prod(ray, c[closest.figure].axis) * closest.t + scal_prod(sub_vect(cam, c[closest.figure].center), c[closest.figure].axis);
// 	point = add_vect(cam, num_mult_vec(closest.t, ray));
// 	normal = get_normal(sub_vect(sub_vect(point, c[closest.figure].center), num_mult_vec(m, c[closest.figure].axis)));
// 	intensity = compute_light_cyl(point, normal, num_mult_vec(-1, ray), light, win, c[closest.figure].shine, c);
// 	color = get_color(c[closest.figure].color, c[closest.figure].color, intensity, 1);
// 	r = c[closest.figure].reflect;
// 	if (depth <= 0 || r <= 0)
// 		return (color);
// 	reflect = reflect_ray(normal, num_mult_vec(-1, ray));
// 	reflected_color = raytrace_cyl(point, reflect, c, win, light, 0.001, T_MAX, depth - 1);
// 	color = get_color(get_color(color, color, 1 - r, 1), get_color(reflected_color, color, r, 1), 1, 2);
// 	return (color);
// }

// void		draw_cylinder(t_window *win, t_vector cam, t_cylinder *cylinder, t_light *light)
// {
// 	t_vector	ray;
// 	int			x;
// 	int			y;
// 	int			color;

// 	y = -(WIN_H / 2);
// 	while (y < (WIN_H / 2))
// 	{
// 		x = -(WIN_W / 2);
// 		while (x < (WIN_W / 2))
// 		{
// 			ray = get_viewport(x, y);
// 			color = raytrace_cyl(cam, ray, cylinder, win, light, T_MIN, T_MAX, win->recursion_depth);
// 			mlx_pixel_put(win->mlx_ptr, win->win_ptr, WIN_W / 2 + x, WIN_H / 2 - y - 1, color);
// 			x++;
// 		}
// 		y++;
// 	}	
// }
