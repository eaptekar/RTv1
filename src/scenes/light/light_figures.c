/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 19:31:37 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/23 15:49:30 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light		*light6(void)
{
	static t_light		light[2];

	light[0].type = 1;
	light[0].intensity = 0;
	light[1].type = 2;
	light[1].intensity = 0.8;
	light[1].ray = set_point(0, 0, -10);
	return (light);
}