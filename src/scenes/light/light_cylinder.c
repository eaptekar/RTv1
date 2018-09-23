/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 15:08:45 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/23 15:46:38 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light		*light2(void)
{
	static t_light		light[1];

	light[0].type = 2;
	light[0].intensity = 0.8;
	light[0].ray = set_point(2, 3, 0);
	return (light);
}