/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:29:42 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/21 17:12:15 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light		*light3(void)
{
	static t_light		light[3];

	light[0].type = 1;
	light[0].intensity = 0.1;
	light[1].type = 2;
	light[1].intensity = 0.7;
	light[1].ray = set_point(3, 5, 5);
	light[2].type = 2;
	light[2].intensity = 0.3;
	light[2].ray = set_point(-3, 1, -3);
	return (light);
}
