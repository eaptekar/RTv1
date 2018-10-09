/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:55:10 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/09 19:24:43 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector	mult(double num, t_vector v)
{
	t_vector	res;

	res.x = num * v.x;
	res.y = num * v.y;
	res.z = num * v.z;
	return (res);
}

t_vector	sub(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

t_vector	add(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vector	get_normal(t_vector v)
{
	t_vector	res;
	double		lenght;

	lenght = sqrt(dot(v, v));
	if (lenght == 0)
		ERROR("null normal vector");
	res.x = v.x / lenght;
	res.y = v.y / lenght;
	res.z = v.z / lenght;
	return (res);
}
