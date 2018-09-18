/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:57:26 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/18 17:03:56 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	parse_camera(void)
{
	t_vector	cam;

	cam.x = 0;
	cam.y = 10;
	cam.z = 1;
	return (cam);
}

t_vector	rotate_camera(void)
{
	t_vector	angle;

	angle.x = 32;
	angle.y = 4;
	angle.z = 62;
	return	(angle);
}

t_light		*add_light(void)
{
	static t_light		light[3];

	
	light[0].type = 1;
	light[0].intensity = 0.05;
	light[1].type = 2;
	light[1].intensity = 0.95;
	light[1].ray.x = 0;
	light[1].ray.y = 25;
	light[1].ray.z = 21;
	light[2].type = 2;
	light[2].intensity = 0.4;
	light[2].ray.x = -5;
	light[2].ray.y = 1.2;
	light[2].ray.z = 0;
	return (light);
}

t_plane		*add_plane(void)
{
	static t_plane		plane[6];

	plane[0].center.x = 0;
	plane[0].center.y = 0;
	plane[0].center.z = 30;
	plane[0].normal.x = 0;
	plane[0].normal.y = 0;
	plane[0].normal.z = 31;
	plane[0].normal = sub(plane[0].normal, plane[0].center);
	plane[0].normal = get_normal(plane[0].normal);
	plane[0].shine = 512;
	plane[0].reflect = 1;
	plane[0].color = 0xFFFFFF;
	plane[1].center.x = 0;
	plane[1].center.y = -10;
	plane[1].center.z = 0;
	plane[1].normal.x = 0;
	plane[1].normal.y = -9;
	plane[1].normal.z = 0;
	plane[1].normal = sub(plane[1].normal, plane[1].center);
	plane[1].normal = get_normal(plane[1].normal);
	plane[1].shine = 512;
	plane[1].reflect = 1;
	plane[1].color = 0xFFFFFF;
	plane[2].center.x = 0;
	plane[2].center.y = 30;
	plane[2].center.z = 0;
	plane[2].normal.x = 0;
	plane[2].normal.y = 29;
	plane[2].normal.z = 0;
	plane[2].normal = sub(plane[2].normal, plane[2].center);
	plane[2].normal = get_normal(plane[2].normal);
	plane[2].shine = 512;
	plane[2].reflect = 1;
	plane[2].color = 0xFFFFFF;
	plane[3].center.x = -25;
	plane[3].center.y = 0;
	plane[3].center.z = 0;
	plane[3].normal.x = -24;
	plane[3].normal.y = 0;
	plane[3].normal.z = 0;
	plane[3].normal = sub(plane[1].normal, plane[1].center);
	plane[3].normal = get_normal(plane[1].normal);
	plane[3].shine = 512;
	plane[3].reflect = 1;
	plane[3].color = 0xFFFFFF;
	plane[4].center.x = 25;
	plane[4].center.y = 0;
	plane[4].center.z = 0;
	plane[4].normal.x = 24;
	plane[4].normal.y = 0;
	plane[4].normal.z = 0;
	plane[4].normal = sub(plane[1].normal, plane[1].center);
	plane[4].normal = get_normal(plane[1].normal);
	plane[4].shine = 512;
	plane[4].reflect = 1;
	plane[4].color = 0xFFFFFF;
	plane[5].center.x = 0;
	plane[5].center.y = 0;
	plane[5].center.z = -30;
	plane[5].normal.x = 0;
	plane[5].normal.y = 0;
	plane[5].normal.z = -29;
	plane[5].normal = sub(plane[1].normal, plane[1].center);
	plane[5].normal = get_normal(plane[1].normal);
	plane[5].shine = 512;
	plane[5].reflect = 1;
	plane[5].color = 0xFFFFFF;
	return (plane);
}

t_sphere		*add_sphere(void)
{
	static t_sphere	sphere[9];

	sphere[0].center.x = 0;
	sphere[0].center.y = 0;
	sphere[0].center.z = 10;
	sphere[0].radius = 2;
	sphere[0].shine = 512;
	sphere[0].reflect = 1;
	sphere[0].color = 0xFFFFFF;
	sphere[1].center.x = 0;
	sphere[1].center.y = 0;
	sphere[1].center.z = -10;
	sphere[1].radius = 2;
	sphere[1].shine = 512;
	sphere[1].reflect = 1;
	sphere[1].color = 0xFFFFFF;
	sphere[2].center.x = 2;
	sphere[2].center.y = -1;
	sphere[2].center.z = 10;
	sphere[2].radius = 0.5;
	sphere[2].shine = 1000;
	sphere[2].reflect = 0;
	sphere[2].color = 0x80DDFF;
	sphere[3].center.x = -2;
	sphere[3].center.y = -1;
	sphere[3].center.z = 10;
	sphere[3].radius = 0.5;
	sphere[3].shine = 1000;
	sphere[3].reflect = 0;
	sphere[3].color = 0x80DDFF;
	sphere[4].center.x = 2;
	sphere[4].center.y = 2;
	sphere[4].center.z = 6;
	sphere[4].radius = 0.5;
	sphere[4].shine = 1000;
	sphere[4].reflect = 0;
	sphere[4].color = 0x80DDFF;
	sphere[5].center.x = -2;
	sphere[5].center.y = 2;
	sphere[5].center.z = 6;
	sphere[5].radius = 0.5;
	sphere[5].shine = 1000;
	sphere[5].reflect = 0;
	sphere[5].color = 0x80DDFF;
	sphere[6].center.x = 2;
	sphere[6].center.y = 2;
	sphere[6].center.z = 10;
	sphere[6].radius = 0.5;
	sphere[6].shine = 1000;
	sphere[6].reflect = 0;
	sphere[6].color = 0x80DDFF;
	sphere[7].center.x = -2;
	sphere[7].center.y = 2;
	sphere[7].center.z = 10;
	sphere[7].radius = 0.5;
	sphere[7].shine = 1000;
	sphere[7].reflect = 0;
	sphere[7].color = 0x80DDFF;
	sphere[8].center.x = 0;
	sphere[8].center.y = -0.5;
	sphere[8].center.z = 6.25;
	sphere[8].radius = 0.5;
	sphere[8].shine = 1000;
	sphere[8].reflect = 1;
	sphere[8].color = 0x80DDFF;
	return (sphere);
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
	cylinder[0].axis = sub(cylinder[0].axis, cylinder[0].center);
	cylinder[0].axis = get_normal(cylinder[0].axis);
	cylinder[0].radius = 0.3;
	cylinder[0].maxm = 2;
	cylinder[0].shine = 1000;
	cylinder[0].reflect = 0;
	cylinder[0].color = 0x80DDFF;
	cylinder[1].center.x = -2;
	cylinder[1].center.y = 0;
	cylinder[1].center.z = 6;
	cylinder[1].axis.x = -2;
	cylinder[1].axis.y = 1;
	cylinder[1].axis.z = 6;
	cylinder[1].axis = sub(cylinder[1].axis, cylinder[1].center);
	cylinder[1].axis = get_normal(cylinder[1].axis);
	cylinder[1].radius = 0.3;
	cylinder[1].maxm = 2;
	cylinder[1].shine = 1000;
	cylinder[1].reflect = 0;
	cylinder[1].color = 0x80DDFF;
	cylinder[2].center.x = 2;
	cylinder[2].center.y = 0;
	cylinder[2].center.z = 10;
	cylinder[2].axis.x = 2;
	cylinder[2].axis.y = 1;
	cylinder[2].axis.z = 10;
	cylinder[2].axis = sub(cylinder[2].axis, cylinder[2].center);
	cylinder[2].axis = get_normal(cylinder[2].axis);
	cylinder[2].radius = 0.3;
	cylinder[2].maxm = 2;
	cylinder[2].shine = 1000;
	cylinder[2].reflect = 0;
	cylinder[2].color = 0x80DDFF;
	cylinder[3].center.x = -2;
	cylinder[3].center.y = 0;
	cylinder[3].center.z = 10;
	cylinder[3].axis.x = -2;
	cylinder[3].axis.y = 1;
	cylinder[3].axis.z = 10;
	cylinder[3].axis = sub(cylinder[3].axis, cylinder[3].center);
	cylinder[3].axis = get_normal(cylinder[3].axis);
	cylinder[3].radius = 0.3;
	cylinder[3].maxm = 2;
	cylinder[3].shine = 1000;
	cylinder[3].reflect = 0;
	cylinder[3].color = 0x80DDFF;
	return (cylinder);
}

t_cone		*add_cone(void)
{
	static t_cone		cone[4];

	cone[0].center.x = 0;
	cone[0].center.y = 0;
	cone[0].center.z = 8;
	cone[0].axis.x = 0;
	cone[0].axis.y = -1;
	cone[0].axis.z = 8;
	cone[0].axis = sub(cone[0].axis, cone[0].center);
	cone[0].axis = get_normal(cone[0].axis);
	cone[0].k = 0.4;
	cone[0].minm = 0;	
	cone[0].maxm = 2;
	cone[0].shine = -1;
	cone[0].reflect = 1;
	cone[0].color = 0xFA78D0;
	return (cone);
}

void	parse_figures(t_window win)
{
	t_scene		scene;

	scene.cam = parse_camera();
	scene.angle = rotate_camera();
	scene.plane = add_plane();
	scene.planes = 6;
	scene.sphere = add_sphere();
	scene.spheres = 2;
	scene.cylinder = add_cylinder();
	scene.cylinders = 0;
	scene.cone = add_cone();
	scene.cones = 0;
	scene.figures = scene.planes + scene.spheres + \
	scene.cylinders + scene.cones;
	scene.light = add_light();
	scene.sources = 3;
	scene.recursion_depth = 5;
	draw_scene(win, scene);
}
