/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_sphere_mirror.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:59:44 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/23 15:50:50 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light		*light8(void)
{
	static t_light		light[2];

	light[0].type = 1;
	light[0].intensity = 0.01;
	light[1].type = 2;
	light[1].intensity = 1.1;
	light[1].ray = set_point(0, 20, 75);
	return (light);
}