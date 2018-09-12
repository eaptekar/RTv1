/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:57:26 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/12 00:11:39 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	parse_camera(void)
{
	t_vector	cam;

	cam.x = 0;
	cam.y = 0;
	cam.z = 0;
	return (cam);
}

t_light		*add_light(t_window *win)
{
	static t_light		light[3];

	win->sources = 3;	
	light[0].type = 1;
	light[0].intensity = 0.2;
	light[1].type = 2;
	light[1].intensity = 0.6;
	light[1].ray.x = 2;
	light[1].ray.y = 1;
	light[1].ray.z = 0;
	light[2].type = 3;
	light[2].intensity = 0.2;
	light[2].ray.x = 1;
	light[2].ray.y = 4;
	light[2].ray.z = 4;
	return (light);
}

void	parse_figures(t_window *win)
{
	t_sphere	sphere[4];
	t_vector	cam;
	t_light		*light;

	win->figures = 4;
	sphere[0].center.x = 0;
	sphere[0].center.y = -1;
	sphere[0].center.z = 4;
	sphere[0].radius = 1;
	sphere[0].shine = 500;
	sphere[0].reflect = 0.2;
	sphere[0].color = 0xFF0000;
	sphere[1].center.x = 2;
	sphere[1].center.y = 0;
	sphere[1].center.z = 7;
	sphere[1].radius = 1;
	sphere[1].shine = -1;
	sphere[1].reflect = 0.7;
	sphere[1].color = 0x0000FF;
	sphere[2].center.x = -1;
	sphere[2].center.y = 0;
	sphere[2].center.z = 5;
	sphere[2].radius = 0.75;
	sphere[2].shine = 1000;
	sphere[2].reflect = 0.5;
	sphere[2].color = 0x00FF00;
	sphere[3].center.x = 0;
	sphere[3].center.y = -5001;
	sphere[3].center.z = 0;
	sphere[3].radius = 5000;
	sphere[3].shine = 100;
	sphere[3].reflect = 0;
	sphere[3].color = 0xFFFF00;
	cam = parse_camera();
	light = add_light(win);
	win->recursion_depth = 3;
	draw_sphere(win, cam, sphere, light);
}
