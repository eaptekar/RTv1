/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 21:09:09 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/18 21:37:04 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	matrix_mult(t_vector vec, t_vector angle)
{
	t_vector	res;
	double		ar;
	double		br;
	double		cr;

	ar = deg_to_rad(angle.x);
	br = deg_to_rad(angle.y);
	cr = deg_to_rad(angle.z);
	res.x = vec.x * cos(br) * cos(cr) - vec.y * cos(br) * sin(cr) + \
	vec.z * sin(br);
	res.y = vec.x * (sin(ar) * sin(br) * cos(cr) + cos(ar) * sin(cr)) + \
	vec.y * (cos(ar) * cos(cr) - sin(ar) * sin(br) * sin(cr)) - \
	vec.z * sin(ar) * cos(br);
	res.z = vec.x * (-cos(ar) * sin(br) * cos(cr) + sin(ar) * sin(cr)) + \
	vec.y * (sin(ar) * cos(cr) + cos(ar) * sin(br) * sin(cr)) + \
	vec.z * cos(ar) * cos(br);
	return (res);
}

t_vector	set_point(double x, double y, double z)
{
	t_vector	cam;

	cam.x = x;
	cam.y = y;
	cam.z = z;
	return (cam);
}

t_plane		parse_plane(int shine, double reflect, int color)
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
	// plane.normal = get_normal(sub(p.normal, p.center));
	plane.shine = shine;
	plane.reflect = reflect;
	plane.color = color;
	return (plane);
}