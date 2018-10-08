/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 15:18:11 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/08 17:25:02 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vector	set_point(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

static t_vector	rotate(t_vector vector, t_vector basis, double angle)
{
	double			phi;
	double			sinphi;
	t_quaternion	q;
	t_quaternion	p;
	t_vector		result;

	phi = deg_to_rad(angle);
	sinphi = sin(phi / 2.0);
	q = normal_quat(new_quat(cos(phi / 2.0), basis.x * sinphi, \
		basis.y * sinphi, basis.z * sinphi));
	p = new_quat(0, vector.x, vector.y, vector.z);
	p = mult_quat(q, mult_quat(p, inverse_quat(q)));
	result.x = p.i;
	result.y = p.j;
	result.z = p.k;
	return (result);
}

t_vector		rotate_camera(t_vector vec, t_vector angle)
{
	t_vector	basis;

	basis = set_point(1.0, 0.0, 0.0);
	vec = rotate(vec, basis, angle.x);
	basis = set_point(0.0, 1.0, 0.0);
	vec = rotate(vec, basis, angle.y);
	basis = set_point(0.0, 0.0, 1.0);
	vec = rotate(vec, basis, angle.z);
	return (vec);
}
