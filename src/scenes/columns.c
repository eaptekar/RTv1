/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:57:26 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/23 15:50:01 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_plane		*add_plane(void)
{
	static t_plane		plane[3];

	plane[0] = init_plane(set_point(0, -1, 10), set_point(0, 0, 10));
	plane[0] = parse_plane(plane[0], 1000, 0, 0xACFD69);
	plane[1] = init_plane(set_point(0, 2, 10), set_point(0, 1, 10));
	plane[1] = parse_plane(plane[1], 1000, 0, 0x808080);
	plane[2] = init_plane(set_point(0, 0, 15), set_point(0, 0, 14));
	plane[2] = parse_plane(plane[2], -1, 0, 0x4F4FFD);
	return (plane);
}

static t_sphere		*add_sphere(void)
{
	static t_sphere	sphere[9];

	sphere[0] = init_sphere(set_point(2, -1, 6), 0.5);
	sphere[0] = parse_sphere(sphere[0], 1000, 0, 0x80DDFF);
	sphere[1] = init_sphere(set_point(-2, -1, 6), 0.5);
	sphere[1] = parse_sphere(sphere[1], 1000, 0, 0x80DDFF);
	sphere[2] = init_sphere(set_point(2, -1, 10), 0.5);
	sphere[2] = parse_sphere(sphere[2], 1000, 0, 0x80DDFF);
	sphere[3] = init_sphere(set_point(-2, -1, 10), 0.5);
	sphere[3] = parse_sphere(sphere[3], 1000, 0, 0x80DDFF);
	sphere[4] = init_sphere(set_point(2, 2, 6), 0.5);
	sphere[4] = parse_sphere(sphere[4], 1000, 0, 0x80DDFF);
	sphere[5] = init_sphere(set_point(-2, 2, 6), 0.5);
	sphere[5] = parse_sphere(sphere[5], 1000, 0, 0x80DDFF);
	sphere[6] = init_sphere(set_point(2, 2, 10), 0.5);
	sphere[6] = parse_sphere(sphere[6], 1000, 0, 0x80DDFF);
	sphere[7] = init_sphere(set_point(-2, 2, 10), 0.5);
	sphere[7] = parse_sphere(sphere[7], 1000, 0, 0x80DDFF);
	sphere[8] = init_sphere(set_point(0, -0.5, 6), 0.5);
	sphere[8] = parse_sphere(sphere[8], -1, 1, 0x80DDFF);
	return (sphere);
}

static t_cylinder	*add_cylinder(void)
{
	static t_cylinder		cylinder[4];

	cylinder[0] = init_cylinder(set_point(2, 0, 6), set_point(2, 1, 6), 0.3);
	cylinder[0] = parse_cylinder(cylinder[0], 1000, 0, 0x80DDFF);
	cylinder[1] = init_cylinder(set_point(-2, 0, 6), set_point(-2, 1, 6), 0.3);
	cylinder[1] = parse_cylinder(cylinder[1], 1000, 0, 0x80DDFF);
	cylinder[2] = init_cylinder(set_point(2, 0, 10), set_point(2, 1, 10), 0.3);
	cylinder[2] = parse_cylinder(cylinder[2], 1000, 0, 0x80DDFF);
	cylinder[3] = init_cylinder(set_point(-2, 0, 10), set_point(-2, 1, 10), \
		0.3);
	cylinder[3] = parse_cylinder(cylinder[3], 1000, 0, 0x80DDFF);
	return (cylinder);
}

static t_cone		*add_cone(void)
{
	static t_cone		cone[1];

	cone[0] = init_cone(set_point(3, 1, -2), set_point(3, 0, -2), 0.4);
	cone[0] = parse_cone(cone[0], -1, 0, 0xFA78D0);
	return (cone);
}

void				scene7(t_window *win)
{
	t_scene		scene;

	scene.cam = set_point(0, 0, 0);
	scene.angle = set_point(0, 0, 0);
	scene.plane = add_plane();
	scene.planes = 3;
	scene.sphere = add_sphere();
	scene.spheres = 9;
	scene.cylinder = add_cylinder();
	scene.cylinders = 4;
	scene.cone = add_cone();
	scene.cones = 1;
	scene.figures = scene.planes + scene.spheres + \
	scene.cylinders + scene.cones;
	scene.light = light7();
	scene.sources = 3;
	scene.recursion_depth = 3;
	draw_scene(win, scene);
}
