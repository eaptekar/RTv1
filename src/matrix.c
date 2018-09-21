/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:13:38 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/21 16:31:32 by eaptekar         ###   ########.fr       */
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

t_quaternion	new_quat(double r, double i, double j, double k)
{
	t_quaternion	q;

	q.r = r;
	q.i = i;
	q.j = j;
	q.k = k;
	return (q);
}

double			lenght_quat(t_quaternion q)
{
	return (sqrt(q.r * q.r + q.i * q.i + q.j * q.j + q.k * q.k));
}

t_quaternion	normal_quat(t_quaternion q)
{
	t_quaternion	normal;

	normal = new_quat(q.r, q.i / lenght_quat(q), q.j / lenght_quat(q), q.k / lenght_quat(q));
	return (normal);
}

t_quaternion	inverse_quat(t_quaternion q)
{
	t_quaternion	inverse;

	inverse = new_quat(q.r / lenght_quat(q), -q.i / lenght_quat(q), -q.j / lenght_quat(q), -q.k / lenght_quat(q));
	return (inverse);
}

t_quaternion	mult_quat(t_quaternion q, t_quaternion p)
{
	t_quaternion	new;

	new.r = q.r * p.r - q.i * p.i - q.j * p.j - q.k * p.k;
	new.i = q.r * p.i + q.i * p.r + q.j * p.k - q.k * p.j;
	new.j = q.r * p.j - q.i * p.k + q.j * p.r + q.k * p.i;
	new.k = q.r * p.k + q.i * p.j - q.j * p.i + q.k * p.r;
	return (new);
}

t_vector		rotate(t_vector vector, double i, double j, double k, double angle)
{
	double	phi;
	double	cosphi;
	double	sinphi;
	t_quaternion	q;
	t_quaternion	p;
	t_vector		result;

	phi = deg_to_rad(angle);
	cosphi = cos(phi / 2.0);
	sinphi = sin(phi / 2.0);
	q = normal_quat(new_quat(cosphi, i * sinphi, j * sinphi, k * sinphi));
	p = new_quat(0, vector.x, vector.y, vector.z);
	p = mult_quat(q, mult_quat(p, inverse_quat(q)));
	result.x = p.i;
	result.y = p.j;
	result.z = p.k;
	return(result);
}

t_vector	rotate_camera(t_vector vec, t_vector angle)
{
	vec = rotate(vec, 1.0, 0.0, 0.0, angle.x);
	vec = rotate(vec, 0.0, 1.0, 0.0, angle.y);
	vec = rotate(vec, 0.0, 0.0, 1.0, angle.z);
	return(vec);
}