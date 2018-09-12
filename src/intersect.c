/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:41:59 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/12 19:56:04 by eaptekar         ###   ########.fr       */
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

t_roots		plane_intersect(t_vector cam, t_vector ray, t_plane p)
{
	t_roots	t;

	if (scal_prod(ray, p.normal))
	{
		t.t1 = -scal_prod(sub_vect(cam, p.center), p.normal) / scal_prod(ray, p.normal);
		t.t2 = t.t1;
		return (t);
	}
	else
	{
		t.t1 = T_MAX;
		t.t2 = T_MAX;
		return (t);
	}
}