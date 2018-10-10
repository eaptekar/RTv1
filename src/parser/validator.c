/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:50:03 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/10 19:35:52 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_vector(t_vector vec, char *value)
{
	int		state;

	state = 0;
	if (vec.x < -1000 || vec.x > 1000)
		state++;
	if (vec.y < -1000 || vec.y > 1000)
		state++;
	if (vec.z < -1000 || vec.z > 1000)
		state++;
	if (state)
	{
		ft_putstr(value);
		ERROR("out of bounds");
	}
}

void	check_plane(t_plane **plane)
{
	check_vector((*plane)->center, "plane->center");
	if ((*plane)->shine <= 0)
		(*plane)->shine = -1;
	else if ((*plane)->shine >= 1 && (*plane)->shine < 5)
		(*plane)->shine = 5;
	else if ((*plane)->shine > 1000)
		(*plane)->shine = 1000;
	if ((*plane)->reflect < 0)
		(*plane)->reflect = 0;
	else if ((*plane)->reflect > 1)
		(*plane)->reflect = 1;
}

void	check_sphere(t_sphere **sphere)
{
	check_vector((*sphere)->center, "sphere->center");
	if ((*sphere)->radius < 0.05)
		(*sphere)->radius = 0.05;
	else if ((*sphere)->radius > 100)
		(*sphere)->radius = 100;
	if ((*sphere)->shine <= 0)
		(*sphere)->shine = -1;
	else if ((*sphere)->shine >= 1 && (*sphere)->shine < 5)
		(*sphere)->shine = 5;
	else if ((*sphere)->shine > 1000)
		(*sphere)->shine = 1000;
		if ((*sphere)->reflect < 0)
		(*sphere)->reflect = 0;
	else if ((*sphere)->reflect > 1)
		(*sphere)->reflect = 1;
}

void	check_cylinder(t_cylinder **cylinder)
{
	check_vector((*cylinder)->center, "cylinder->center");
	if ((*cylinder)->radius < 0.05)
		(*cylinder)->radius = 0.05;
	else if ((*cylinder)->radius > 100)
		(*cylinder)->radius = 100;
	if ((*cylinder)->shine <= 0)
		(*cylinder)->shine = -1;
	else if ((*cylinder)->shine >= 1 && (*cylinder)->shine < 5)
		(*cylinder)->shine = 5;
	else if ((*cylinder)->shine > 1000)
		(*cylinder)->shine = 1000;
		if ((*cylinder)->reflect < 0)
		(*cylinder)->reflect = 0;
	else if ((*cylinder)->reflect > 1)
		(*cylinder)->reflect = 1;
}

void	check_cone(t_cone **cone)
{
	check_vector((*cone)->center, "cone->center");
	if ((*cone)->k < 0.01)
		(*cone)->k = 0.01;
	else if ((*cone)->k > 4)
		(*cone)->k = 4;
	if ((*cone)->shine <= 0)
		(*cone)->shine = -1;
	else if ((*cone)->shine >= 1 && (*cone)->shine < 5)
		(*cone)->shine = 5;
	else if ((*cone)->shine > 1000)
		(*cone)->shine = 1000;
		if ((*cone)->reflect < 0)
		(*cone)->reflect = 0;
	else if ((*cone)->reflect > 1)
		(*cone)->reflect = 1;
}
