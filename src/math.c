/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:55:10 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/16 00:51:33 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		scal_prod(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector	num_mult_vec(double num, t_vector v)
{
	t_vector	res;

	res.x = num * v.x;
	res.y = num * v.y;
	res.z = num * v.z;
	return (res);
}

t_vector	get_normal(t_vector v)
{
	t_vector	res;
	double		lenght;

	lenght = sqrt(scal_prod(v, v));
	res.x = v.x / lenght;
	res.y = v.y / lenght;
	res.z = v.z / lenght;
	return (res);
}

t_vector	sub_vect(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

t_vector	add_vect(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vector	matrix_mult(t_vector vec, double a, double b, double c)
{
	t_vector	res;
	double		ar;
	double		br;
	double		cr;

	ar = deg_to_rad(a);
	br = deg_to_rad(b);
	cr = deg_to_rad(c);
	res.x = vec.x * cos(br) * cos(cr) - vec.y * cos(br) * sin(cr) + vec.z * sin(br);
	res.y = vec.x * (sin(ar) * sin(br) * cos(cr) + cos(ar) * sin(cr)) + vec.y * (cos(ar) * cos(cr) - sin(ar) * sin(br) * sin(cr)) - vec.z * sin(ar) * cos(br);
	res.z = vec.x * (-cos(ar) * sin(br) * cos(cr) + sin(ar) * sin(cr)) + vec.y * (sin(ar) * cos(cr) + cos(ar) * sin(br) * sin(cr)) + vec.z * cos(ar) * cos(br);
	return (res);
}