/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:16:32 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/09 18:26:27 by eaptekar         ###   ########.fr       */
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

int			raytrace(t_vector cam, t_vector ray, t_sphere *s, t_window *win, t_light *light)
{
	t_roots		t;
	double		closest_t;
	int			closest_sphere;
	int			color;
	int			i;
	t_vector	point;
	t_vector	normal;
	double		intensity;

	closest_t = T_MAX;
	closest_sphere = -1;
	i = 0;
	while (i < win->figures)
	{
		t = get_roots(cam, ray, s[i]);
		if (t.t1 < closest_t && (t.t1 < T_MAX && t.t1 > T_MIN))
		{
			closest_t = t.t1;
			closest_sphere = i;
		}
		if (t.t2 < closest_t && (t.t2 < T_MAX && t.t2 > T_MIN))
		{
			closest_t = t.t2;
			closest_sphere = i;
		}
		i++;
	}
	if (closest_sphere == -1)
	{
		color = 0xFFFFFF;
		return (color);
	}
	point = add_vect(cam, num_mult_vec(closest_t, ray));
	normal = get_normal(sub_vect(point, s[closest_sphere].center));
	intensity = compute_light(point, normal, num_mult_vec(-1, ray), light, win->sources, s[closest_sphere].shine);
	color = get_color(s[closest_sphere].color, intensity);
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
			color = raytrace(cam, ray, sphere, win, light);
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, WIN_W / 2 + x, WIN_H / 2 - y - 1, color);
			x++;
		}
		y++;
	}	
}
