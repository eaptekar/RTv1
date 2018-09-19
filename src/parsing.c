/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 21:09:09 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/19 15:22:18 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	set_point(double x, double y, double z)
{
	t_vector	cam;

	cam.x = x;
	cam.y = y;
	cam.z = z;
	return (cam);
}

t_plane		parse_plane(t_plane p, int shine, double reflect, int color)
{
	t_plane		plane;

	if (shine < -1 || shine == 0)
		shine = -1;
	else if (shine > 1000)
		shine = 1000;
	if (reflect < 0)
		reflect = 0;
	else if (reflect > 1)
		reflect = 1;
	plane.center = p.center;
	plane.normal = p.normal;
	plane.shine = shine;
	plane.reflect = reflect;
	plane.color = color;
	return (plane);
}

t_sphere	parse_sphere(t_sphere s, int shine, double reflect, int color)
{
	t_sphere	sphere;

	if (shine < -1 || shine == 0)
		shine = -1;
	else if (shine > 1000)
		shine = 1000;
	if (reflect < 0)
		reflect = 0;
	else if (reflect > 1)
		reflect = 1;
	sphere.center = s.center;
	sphere.radius = s.radius;
	sphere.shine = shine;
	sphere.reflect = reflect;
	sphere.color = color;
	return (sphere);
}

t_cylinder	parse_cylinder(t_cylinder c, int shine, double reflect, int color)
{
	t_cylinder	cylinder;

	if (shine < -1 || shine == 0)
		shine = -1;
	else if (shine > 1000)
		shine = 1000;
	if (reflect < 0)
		reflect = 0;
	else if (reflect > 1)
		reflect = 1;
	cylinder.center = c.center;
	cylinder.radius = c.radius;
	cylinder.axis = c.axis;
	cylinder.maxm = c.maxm;
	cylinder.shine = shine;
	cylinder.reflect = reflect;
	cylinder.color = color;
	return (cylinder);
}

t_cone		parse_cone(t_cone c, int shine, double reflect, int color)
{
	t_cone	cone;

	if (shine < -1 || shine == 0)
		shine = -1;
	else if (shine > 1000)
		shine = 1000;
	if (reflect < 0)
		reflect = 0;
	else if (reflect > 1)
		reflect = 1;
	cone.center = c.center;
	cone.k = c.k;
	cone.axis = c.axis;
	cone.maxm = c.maxm;
	cone.shine = shine;
	cone.reflect = reflect;
	cone.color = color;
	return (cone);
}
