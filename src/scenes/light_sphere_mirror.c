/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_sphere_mirror.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:59:44 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/19 16:57:38 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light		*light2(void)
{
	static t_light		light[3];

	light[0].type = 1;
	light[0].intensity = 0.05;
	light[1].type = 2;
	light[1].intensity = 1.0;
	light[1].ray = set_point(0, 25, 70);
	light[2].type = 2;
	light[2].intensity = 0.4;
	light[2].ray = set_point(-5, 1.2, 0);
	return (light);
}