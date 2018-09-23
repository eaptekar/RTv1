/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 15:18:11 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/23 15:20:48 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
