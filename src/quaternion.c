/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:13:38 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/08 17:26:17 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

	normal = new_quat(q.r, q.i / lenght_quat(q), \
		q.j / lenght_quat(q), q.k / lenght_quat(q));
	return (normal);
}

t_quaternion	inverse_quat(t_quaternion q)
{
	t_quaternion	inverse;

	inverse = new_quat(q.r / lenght_quat(q), -q.i / lenght_quat(q), \
		-q.j / lenght_quat(q), -q.k / lenght_quat(q));
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
