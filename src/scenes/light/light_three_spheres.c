/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_three_spheres.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 17:19:58 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/21 17:31:23 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light		*light4(void)
{
	static t_light		light[3];

	light[0].type = 1;
	light[0].intensity = 0.2;
	light[1].type = 2;
	light[1].intensity = 0.6;
	light[1].ray = set_point(2, 1, 0);
	light[2].type = 3;
	light[2].intensity = 0.2;
	light[2].ray = set_point(1, 4, 4);
	return (light);
}
