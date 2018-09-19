/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:13:38 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/19 15:13:54 by eaptekar         ###   ########.fr       */
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
