/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 18:39:02 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/23 15:49:02 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
	
#include "rtv1.h"

static t_plane		*add_plane(void)
{
	static t_plane		plane[1];

	plane[0] = init_plane(set_point(-200, -100, 300), set_point(-199, -100, 299));
	plane[0] = parse_plane(plane[0], 400, 0, 0x808080);
	return (plane);
}

static t_sphere		*add_sphere(void)
{
	static t_sphere	sphere[11];

	sphere[0] = init_sphere(set_point(-1, 6, 48), 1);
	sphere[0] = parse_sphere(sphere[0], 1000, 0, 0xfff132);
	sphere[1] = init_sphere(set_point(-25, 3, 3), 3);
	sphere[1] = parse_sphere(sphere[1], 1000, 0, 0x28ff37);
	sphere[2] = init_sphere(set_point(4, -9, 0), 3);
	sphere[2] = parse_sphere(sphere[2], 1000, 0, 0xb3ff7c);
	sphere[3] = init_sphere(set_point(-24, -23, 8), 1.5);
	sphere[3] = parse_sphere(sphere[3], 1000, 0, 0xec54f9);
	sphere[4] = init_sphere(set_point(7, 4, 15), 2);
	sphere[4] = parse_sphere(sphere[4], 1000, 0, 0xffd36d);
	sphere[5] = init_sphere(set_point(-20, -2, 25), 6);
	sphere[5] = parse_sphere(sphere[5], 1000, 0, 0xe84040);
	sphere[6] = init_sphere(set_point(-3, -6, 39), 2);
	sphere[6] = parse_sphere(sphere[6], 1000, 0, 0xff8419);
	sphere[7] = init_sphere(set_point(-13, -32, 49), 2);
	sphere[7] = parse_sphere(sphere[7], 1000, 0, 0xff2b5c);
	sphere[8] = init_sphere(set_point(4, -20, 0), 1.25);
	sphere[8] = parse_sphere(sphere[8], 1000, 0, 0x7501c1);
	sphere[9] = init_sphere(set_point(17, 27, 56), 2);
	sphere[9] = parse_sphere(sphere[9], 1000, 0, 0xff91ca);
	sphere[10] = init_sphere(set_point(-9, 13, 0), 1.25);
	sphere[10] = parse_sphere(sphere[10], 1000, 0, 0xeffffd);
	return (sphere);
}

static t_cylinder	*add_cylinder(void)
{
	static t_cylinder		cylinder[3];

	cylinder[0] = init_cylinder(set_point(5, -3, 11), set_point(15, 5, 21), 1);
	cylinder[0] = parse_cylinder(cylinder[0], -1, 0, 0x4fddcd);
	cylinder[1] = init_cylinder(set_point(-10, 10, 20), set_point(0, 18, 30), 3);
	cylinder[1] = parse_cylinder(cylinder[1], -1, 0, 0x59c5e0);
	cylinder[2] = init_cylinder(set_point(0, 5, 50), set_point(10, 13, 60), 1);
	cylinder[2] = parse_cylinder(cylinder[2], -1, 0, 0x2128ef);
	return (cylinder);
}

static t_cone		*add_cone(void)
{
	static t_cone		cone[0];

	return (cone);
}

void				scene6(t_window *win)
{
	t_scene		scene;

	scene.cam = set_point(0, -5, -40);
	scene.angle = set_point(0, -12, 0);
	scene.plane = add_plane();
	scene.planes = 1;
	scene.sphere = add_sphere();
	scene.spheres = 11;
	scene.cylinder = add_cylinder();
	scene.cylinders = 3;
	scene.cone = add_cone();
	scene.cones = 0;
	scene.figures = scene.planes + scene.spheres + \
	scene.cylinders + scene.cones;
	scene.light = light6();
	scene.sources = 2;
	scene.recursion_depth = 0;
	draw_scene(win, scene);
}
