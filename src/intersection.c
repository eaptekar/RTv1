/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:16:32 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/18 18:03:30 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_roots		plane_intersect(t_vector cam, t_vector ray, t_plane p)
{
	t_roots	t;

	if (dot(ray, p.normal))
	{
		t.t1 = -dot(sub(cam, p.center), p.normal) / dot(ray, p.normal);
		t.t2 = t.t1;
		t.type = 1;
		return (t);
	}
	else
	{
		t.t1 = T_MAX;
		t.t2 = T_MAX;
		t.type = 1;
		return (t);
	}
}

t_roots		sphere_intersect(t_vector cam, t_vector ray, t_sphere s)
{
	double		a;
	double		b;
	double		c;
	double		discr;
	t_roots		t;

	a = dot(ray, ray);
	b = 2 * dot(sub(cam, s.center), ray);
	c = dot(sub(cam, s.center), sub(cam, s.center)) - s.radius * s.radius;
	discr = b * b - 4 * a * c;
	if (discr < 0)
	{
		t.t1 = T_MAX;
		t.t2 = T_MAX;
		t.type = 2;
		return (t);
	}
	t.t1 = (-b + sqrt(discr)) / (2 * a);
	t.t2 = (-b - sqrt(discr)) / (2 * a);
	t.type = 2;
	return (t);
}

t_roots		cyl_intersect(t_vector cam, t_vector ray, t_cylinder c)
{
	double		a;
	double		b;
	double		ci;
	double		discr;
	t_roots		t;

	a = dot(ray, ray) - pow(dot(ray, c.axis), 2);
	b = 2 * (dot(ray, sub(cam, c.center)) - dot(ray, c.axis) * \
		dot(sub(cam, c.center), c.axis));
	ci = dot(sub(cam, c.center), sub(cam, c.center)) - \
	pow(dot(sub(cam, c.center), c.axis), 2) - c.radius * c.radius;
	discr = b * b - 4 * a * ci;
	if (discr < 0)
	{
		t.t1 = T_MAX;
		t.t2 = T_MAX;
		t.type = 3;
		return (t);
	}
	t.t1 = (-b + sqrt(discr)) / (2 * a);
	t.t2 = (-b - sqrt(discr)) / (2 * a);
	t.type = 3;
	return (t);
}

t_roots		cone_intersect(t_vector cam, t_vector ray, t_cone c)
{
	double		a;
	double		b;
	double		ci;
	double		discr;
	t_roots		t;

	a = dot(ray, ray) - pow(dot(ray, c.axis), 2) * (1 + c.k * c.k);
	b = 2 * (dot(ray, sub(cam, c.center)) - (1 + c.k * c.k) * dot(ray, c.axis) \
		* dot(sub(cam, c.center), c.axis));
	ci = dot(sub(cam, c.center), sub(cam, c.center)) - (1 + c.k * c.k) * \
	pow(dot(sub(cam, c.center), c.axis), 2);
	discr = b * b - 4 * a * ci;
	if (discr < 0)
	{
		t.t1 = T_MAX;
		t.t2 = T_MAX;
		t.type = 4;
		return (t);
	}
	t.t1 = (-b + sqrt(discr)) / (2 * a);
	t.t2 = (-b - sqrt(discr)) / (2 * a);
	t.type = 4;
	return (t);
}

t_roots		get_roots(int i, t_scene s, t_vector cam, t_vector ray)
{
	t_roots		t;

	if (i < s.planes)
	{
		t = plane_intersect(cam, ray, s.plane[i]);
		t.i = i;
	}
	else if (i - s.planes < s.spheres)
	{
		t = sphere_intersect(cam, ray, s.sphere[i - s.planes]);
		t.i = i - s.planes;
	}
	else if (i - s.planes - s.spheres < s.cylinders)
	{
		t = cyl_intersect(cam, ray, s.cylinder[i - s.planes - s.spheres]);
		t.i = i - s.planes - s.spheres;
	}
	else
	{
		t = cone_intersect(cam, ray, s.cone[i - s.planes - s.spheres - \
			s.cylinders]);
		t.i = i - s.planes - s.spheres - s.cylinders;
	}
	return (t);
}
