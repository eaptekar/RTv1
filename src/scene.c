/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:57:26 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/14 15:37:39 by eaptekar         ###   ########.fr       */
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
	light[2].type = 2;
	light[2].intensity = 0.2;
	light[2].ray.x = -2;
	light[2].ray.y = 1;
	light[2].ray.z = 0;
	return (light);
}

t_plane		*add_plane(void)
{
	static t_plane		plane[2];

	plane[0].center.x = 0;
	plane[0].center.y = 0;
	plane[0].center.z = 11;
	plane[0].normal.x = 0;
	plane[0].normal.y = 0;
	plane[0].normal.z = 10;
	plane[0].normal = sub_vect(plane[0].normal, plane[0].center);
	plane[0].normal = get_normal(plane[0].normal);
	plane[0].shine = 1000;
	plane[0].reflect = 0;
	plane[0].color = 0x0000FF;
	plane[1].center.x = 0;
	plane[1].center.y = -5;
	plane[1].center.z = 5;
	plane[1].normal.x = 0;
	plane[1].normal.y = -4;
	plane[1].normal.z = 4;
	plane[1].normal = sub_vect(plane[1].normal, plane[1].center);
	plane[1].normal = get_normal(plane[1].normal);
	plane[1].shine = 1000;
	plane[1].reflect = 0.2;
	plane[1].color = 0xFFFF00;
	// printf("%f %f %f\n", plane[1].normal.x, plane[1].normal.y, plane[1].normal.z);
	return (plane);
}

t_cylinder		*add_cylinder(void)
{
	static t_cylinder		cylinder[4];

	cylinder[0].center.x = 2;
	cylinder[0].center.y = 0;
	cylinder[0].center.z = 6;
	cylinder[0].axis.x = 2;
	cylinder[0].axis.y = 1;
	cylinder[0].axis.z = 6;
	cylinder[0].axis = sub_vect(cylinder[0].axis, cylinder[0].center);
	cylinder[0].axis = get_normal(cylinder[0].axis);
	cylinder[0].radius = 0.25;
	cylinder[0].maxm = 2;
	cylinder[0].shine = -1;
	cylinder[0].reflect = 0;
	cylinder[0].color = 0x808080;
	cylinder[1].center.x = -2;
	cylinder[1].center.y = 0;
	cylinder[1].center.z = 6;
	cylinder[1].axis.x = -2;
	cylinder[1].axis.y = 1;
	cylinder[1].axis.z = 6;
	cylinder[1].axis = sub_vect(cylinder[1].axis, cylinder[1].center);
	cylinder[1].axis = get_normal(cylinder[1].axis);
	cylinder[1].radius = 0.25;
	cylinder[1].maxm = 2;
	cylinder[1].shine = -1;
	cylinder[1].reflect = 0;
	cylinder[1].color = 0x808080;
	cylinder[2].center.x = -2;
	cylinder[2].center.y = 0;
	cylinder[2].center.z = 10;
	cylinder[2].axis.x = -2;
	cylinder[2].axis.y = 1;
	cylinder[2].axis.z = 10;
	cylinder[2].axis = sub_vect(cylinder[2].axis, cylinder[2].center);
	cylinder[2].axis = get_normal(cylinder[2].axis);
	cylinder[2].radius = 0.25;
	cylinder[2].maxm = 2;
	cylinder[2].shine = -1;
	cylinder[2].reflect = 0;
	cylinder[2].color = 0x808080;
	cylinder[3].center.x = 2;
	cylinder[3].center.y = 0;
	cylinder[3].center.z = 10;
	cylinder[3].axis.x = 2;
	cylinder[3].axis.y = 1;
	cylinder[3].axis.z = 10;
	cylinder[3].axis = sub_vect(cylinder[3].axis, cylinder[3].center);
	cylinder[3].axis = get_normal(cylinder[3].axis);
	cylinder[3].radius = 0.25;
	cylinder[3].maxm = 2;
	cylinder[3].shine = -1;
	cylinder[3].reflect = 0;
	cylinder[3].color = 0x808080;
	return (cylinder);
}

void	parse_figures(t_window *win)
{
	t_sphere	sphere[4];
	t_vector	cam;
	t_plane		*plane;
	t_cylinder	*cylinder;
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
	plane = add_plane();
	light = add_light(win);
	win->recursion_depth = 3;
	cylinder = add_cylinder();
	// draw_plane(win, cam, plane, light);
	// draw_sphere(win, cam, sphere, light);
	draw_cylinder(win, cam, cylinder, light);
}
