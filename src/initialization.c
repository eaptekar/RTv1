/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:08:35 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/19 15:21:30 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_plane		init_plane(t_vector center, t_vector normal)
{
	t_plane	plane;

	plane.center = center;
	plane.normal = get_normal(sub(normal, center));
	return (plane);
}

t_sphere	init_sphere(t_vector center, double radius)
{
	t_sphere	sphere;

	if (radius < 0.02)
		radius = 0.02;
	sphere.center = center;
	sphere.radius = radius;
	return (sphere);
}

t_cylinder	init_cylinder(t_vector center, t_vector axis, double radius)
{
	t_cylinder	cylinder;

	if (radius < 0.01)
		radius = 0.01;
	cylinder.center = center;
	cylinder.axis = get_normal(sub(axis, center));
	cylinder.radius = radius;
	cylinder.maxm = 2;
	return (cylinder);
}

t_cone		init_cone(t_vector center, t_vector axis, double k)
{
	t_cone	cone;

	if (k < 0.05)
		k = 0.05;
	cone.center = center;
	cone.axis = get_normal(sub(axis, center));
	cone.k = k;
	cone.minm = 0;
	cone.maxm = 2;
	return (cone);
}
