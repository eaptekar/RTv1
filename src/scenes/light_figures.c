/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 19:31:37 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/21 20:01:58 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light		*light5(void)
{
	static t_light		light[3];

	light[0].type = 1;
	light[0].intensity = 0;
	light[1].type = 2;
	light[1].intensity = 0.8;
	light[1].ray = set_point(0, 0, -10);
	light[2].type = 3;
	light[2].intensity = 0.4;
	light[2].ray = set_point(1, 4, -4);
	return (light);
}