/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:23:39 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/21 17:11:41 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_plane		*add_plane(void)
{
	static t_plane		plane[6];

	plane[0] = init_plane(set_point(0, 0, 35), set_point(0, 0, 34));
	plane[0] = parse_plane(plane[0], -1, 0, 0xf3f7c3);
	plane[1] = init_plane(set_point(0, 10, 0), set_point(0, 9, 0));
	plane[1] = parse_plane(plane[1], -1, 0, 0xf3f7c3);
	plane[2] = init_plane(set_point(11, 0, 0), set_point(10, 0, 0));
	plane[2] = parse_plane(plane[2], -1, 0, 0x51f12e);
	plane[3] = init_plane(set_point(0, -5, 0), set_point(0, -4, 0));
	plane[3] = parse_plane(plane[3], -1, 0, 0xf3f7c3);
	plane[4] = init_plane(set_point(-11, 0, 0), set_point(-10, 0, 0));
	plane[4] = parse_plane(plane[4], -1, 0, 0xf22e2e);
	plane[5] = init_plane(set_point(0, 0, -20), set_point(0, 0, -19));
	plane[5] = parse_plane(plane[5], -1, 0, 0xf3f7c3);
	return (plane);
}

static t_sphere		*add_sphere(void)
{
	static t_sphere	sphere[2];

	sphere[0] = init_sphere(set_point(5, -3, 15), 2);
	sphere[0] = parse_sphere(sphere[0], 1000, 0, 0xf2e71a);
	sphere[1] = init_sphere(set_point(2, -4, 11.5), 1);
	sphere[1] = parse_sphere(sphere[1], 1000, 0.75, 0xC8C814);
	return (sphere);
}

static t_cylinder	*add_cylinder(void)
{
	static t_cylinder		cylinder[1];

	cylinder[0] = init_cylinder(set_point(1, -2, 25), set_point(4, -3, 24), 1);
	cylinder[0] = parse_cylinder(cylinder[0], -1, 0, 0x9a49e5);
	return (cylinder);
}

static t_cone		*add_cone(void)
{
	static t_cone		cone[1];

	cone[0] = init_cone(set_point(-2.8, 1, 22), set_point(-3.0, 0, 21), 0.4);
	cone[0] = parse_cone(cone[0], -1, 0, 0x51b1d1);
	return (cone);
}

void				scene3(t_window *win)
{
	t_scene		scene;

	scene.cam = set_point(6, 5, -4);
	scene.angle = set_point(15, -15, 0);
	scene.plane = add_plane();
	scene.planes = 6;
	scene.sphere = add_sphere();
	scene.spheres = 2;
	scene.cylinder = add_cylinder();
	scene.cylinders = 1;
	scene.cone = add_cone();
	scene.cones = 1;
	scene.figures = scene.planes + scene.spheres + \
	scene.cylinders + scene.cones;
	scene.light = light3();
	scene.sources = 3;
	scene.recursion_depth = 3;
	draw_scene(win, scene);
}
