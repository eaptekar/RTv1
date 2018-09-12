/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:16:32 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/12 00:11:22 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_roots		get_roots(t_vector cam, t_vector ray, t_sphere s)
{
	double		a;
	double		b;
	double		c;
	double		discr;
	t_roots		t;

	a = scal_prod(ray, ray);
	b = 2 * scal_prod(sub_vect(cam, s.center), ray);
	c = scal_prod(sub_vect(cam, s.center), sub_vect(cam, s.center)) - s.radius * s.radius;
	discr = b * b - 4 * a * c;
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

t_closest		closest_intersection(t_window *win, t_vector cam, t_vector ray, t_sphere *s, double t_min, double t_max)
{
	int			i;
	t_closest	closest;
	t_roots		t;

	closest.t = T_MAX;
	closest.sphere = -1;
	i = 0;
	while (i < win->figures)
	{
		t = get_roots(cam, ray, s[i]);
		if (t.t1 < closest.t && (t.t1 < t_max && t.t1 > t_min))
		{
			closest.t = t.t1;
			closest.sphere = i;
		}
		if (t.t2 < closest.t && (t.t2 < t_max && t.t2 > t_min))
		{
			closest.t = t.t2;
			closest.sphere = i;
		}
		i++;
	}
	return (closest);
}

int			raytrace(t_vector cam, t_vector ray, t_sphere *s, t_window *win, t_light *light, double t_min, double t_max, int depth)
{
	t_closest	closest;
	int			color;
	int			reflected_color;
	double		intensity;
	double		r;
	t_vector	point;
	t_vector	normal;
	t_vector	reflect;

	closest = closest_intersection(win, cam, ray, s, t_min, t_max);
	if (closest.sphere == -1)
	{
		color = 0x000000;
		return (color);
	}
	point = add_vect(cam, num_mult_vec(closest.t, ray));
	normal = get_normal(sub_vect(point, s[closest.sphere].center));
	intensity = compute_light(point, normal, num_mult_vec(-1, ray), light, win, s[closest.sphere].shine, s);
	color = get_color(s[closest.sphere].color, s[closest.sphere].color, intensity, 1);
	r = s[closest.sphere].reflect;
	if (depth <= 0 || r <= 0)
		return (color);
	reflect = reflect_ray(normal, num_mult_vec(-1, ray));
	reflected_color = raytrace(point, reflect, s, win, light, 0.001, T_MAX, depth - 1);
	color = get_color(get_color(color, color, 1 - r, 1), get_color(reflected_color, color, r, 1), 1, 2);
	return (color);
}

void		draw_sphere(t_window *win, t_vector cam, t_sphere *sphere, t_light *light)
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
			color = raytrace(cam, ray, sphere, win, light, T_MIN, T_MAX, win->recursion_depth);
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, WIN_W / 2 + x, WIN_H / 2 - y - 1, color);
			x++;
		}
		y++;
	}	
}
