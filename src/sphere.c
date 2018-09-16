/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:16:32 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/16 01:33:15 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_roots		sphere_intersect(t_vector cam, t_vector ray, t_sphere s)
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

t_closest		closest_intersection(t_window *win, t_vector cam, t_vector ray, t_figure figure, double t_min, double t_max)
{
	int			i;
	int			j;
	t_closest	closest;
	t_roots		t;
	int			planes;
	int			spheres;
	int			cylinders;
	int			cones;
	int			type;

	type = 0;
	j = 0;
	closest.t = T_MAX;
	closest.i = -1;
	closest.type = type;
	planes = figure.planes;
	spheres = figure.spheres;
	cylinders = figure.cylinders;
	cones = figure.cones;
	i = 0;
	while (i < win->figures)
	{
		if (planes)
		{
			j = planes - 1;
			t = plane_intersect(cam, ray, figure.plane[j]);
			type = 1;
			planes--;
		}
		else if (spheres)
		{
			j = spheres - 1;
			t = sphere_intersect(cam, ray, figure.sphere[j]);
			type = 2;
			spheres--;
		}
		else if (cylinders)
		{
			j = cylinders - 1;
			t = cyl_intersect(cam, ray, figure.cylinder[j]);
			type = 3;
			cylinders--;
		}
		else if (cones)
		{
			j = cones - 1;
			t = cone_intersect(cam, ray, figure.cone[j]);
			type = 4;
			cones--;	
		}
		if (t.t1 < closest.t && (t.t1 < t_max && t.t1 > t_min))
		{
			closest.t = t.t1;
			closest.i = j;
			closest.type = type;

		}
		if (t.t2 < closest.t && (t.t2 < t_max && t.t2 > t_min))
		{
			closest.t = t.t2;
			closest.i = j;
			closest.type = type;
		}
		i++;
	}
	return (closest);
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
			closest = closest_intersection(win, point, l_dir, figure, 0.001, t_max);
			if (closest.type == 0)
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

int			raytrace(t_vector cam, t_vector ray, t_figure figure, t_window *win, t_light *light, double t_min, double t_max, int depth)
{
	t_closest	closest;
	int			color;
	int			reflected_color;
	int			shine;
	double		intensity;
	double		r;
	t_vector	point;
	t_vector	normal;
	t_vector	reflect;

	double		m;
	double		a;


	closest = closest_intersection(win, cam, ray, figure, t_min, t_max);
	if (closest.type == 0)
	{
		color = 0x000000;
		return (color);
	}
	else if (closest.type == 1)
	{
		point = add_vect(cam, num_mult_vec(closest.t, ray));
		normal = figure.plane[closest.i].normal;
		shine = figure.plane[closest.i].shine;
		color = figure.plane[closest.i].color;
		r = figure.plane[closest.i].reflect;
	}
	else if (closest.type == 2)
	{
		point = add_vect(cam, num_mult_vec(closest.t, ray));
		normal = get_normal(sub_vect(point, figure.sphere[closest.i].center));
		shine = figure.sphere[closest.i].shine;
		color = figure.sphere[closest.i].color;
		r = figure.sphere[closest.i].reflect;
	}
	else if (closest.type == 3)
	{
		m = scal_prod(ray, figure.cylinder[closest.i].axis) * closest.t + scal_prod(sub_vect(cam, figure.cylinder[closest.i].center), figure.cylinder[closest.i].axis);
		point = add_vect(cam, num_mult_vec(closest.t, ray));
		normal = get_normal(sub_vect(sub_vect(point, figure.cylinder[closest.i].center), num_mult_vec(m, figure.cylinder[closest.i].axis)));
		shine = figure.cylinder[closest.i].shine;
		color = figure.cylinder[closest.i].color;
		r = figure.cylinder[closest.i].reflect;
	}
	else
	{
		m = scal_prod(ray, figure.cone[closest.i].axis) * closest.t + scal_prod(sub_vect(cam, figure.cone[closest.i].center), figure.cone[closest.i].axis);
		a = m * figure.cone[closest.i].k * figure.cone[closest.i].k;
		point = add_vect(cam, num_mult_vec(closest.t, ray));
		normal = get_normal(sub_vect(sub_vect(point, figure.cone[closest.i].center), num_mult_vec((1 + figure.cone[closest.i].k * figure.cone[closest.i].k), num_mult_vec(m, figure.cone[closest.i].axis))));
		shine = figure.cone[closest.i].shine;
		color = figure.cone[closest.i].color;
		r = figure.cone[closest.i].reflect;
	}
	intensity = compute_light(point, normal, num_mult_vec(-1, ray), light, win, shine, figure);
	color = get_color(color, 0, intensity, 1);
	if (depth <= 0 || r <= 0)
		return (color);
	reflect = reflect_ray(normal, num_mult_vec(-1, ray));
	reflected_color = raytrace(point, reflect, figure, win, light, 0.001, T_MAX, depth - 1);
	color = get_color(get_color(color, color, 1 - r, 1), get_color(reflected_color, color, r, 1), 1, 2);
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
			ray = matrix_mult(ray, 32, 4, 62);
			color = raytrace(cam, ray, figure, win, light, T_MIN, T_MAX, win->recursion_depth);
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, WIN_W / 2 + x, WIN_H / 2 - y, color);
			x++;
		}
		y++;
	}	
}
