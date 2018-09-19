/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_mirror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:57:26 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/19 16:40:30 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_plane		*add_plane(void)
{
	static t_plane		plane[6];

	plane[0] = init_plane(set_point(0, 0, 100), set_point(0, 0, 99));
	plane[0] = parse_plane(plane[0], 512, 1, 0xFFFFFF);
	plane[1] = init_plane(set_point(0, -10, 0), set_point(0, -9, 0));
	plane[1] = parse_plane(plane[1], 512, 1, 0xFFFFFF);
	plane[2] = init_plane(set_point(0, 30, 0), set_point(0, 29, 0));
	plane[2] = parse_plane(plane[2], 512, 1, 0xFFFFFF);
	plane[3] = init_plane(set_point(-25, 0, 0), set_point(-24, 0, 0));
	plane[3] = parse_plane(plane[3], 512, 1, 0xFFFFFF);
	plane[4] = init_plane(set_point(25, 0, 0), set_point(24, 0, 0));
	plane[4] = parse_plane(plane[4], 512, 1, 0xFFFFFF);
	plane[5] = init_plane(set_point(0, 0, -100), set_point(0, 0, -99));
	plane[5] = parse_plane(plane[5], 512, 1, 0xFFFFFF);
	return (plane);
}

static t_sphere		*add_sphere(void)
{
	static t_sphere	sphere[2];

	sphere[0] = init_sphere(set_point(0, 0, 10), 2);
	sphere[0] = parse_sphere(sphere[0], 512, 1, 0xFFFFFF);
	sphere[1] = init_sphere(set_point(0, 0, -10), 2);
	sphere[1] = parse_sphere(sphere[1], 512, 1, 0xFFFFFF);

	return (sphere);
}

static t_cylinder	*add_cylinder(void)
{
	static t_cylinder		cylinder[0];

	return (cylinder);
}

static t_cone		*add_cone(void)
{
	static t_cone		cone[0];

	return (cone);
}

void				scene2(t_window *win)
{
	t_scene		scene;

	scene.cam = set_point(0, 10.01, 1);
	scene.angle = set_point(50, 10, 40);
	scene.plane = add_plane();
	scene.planes = 6;
	scene.sphere = add_sphere();
	scene.spheres = 2	;
	scene.cylinder = add_cylinder();
	scene.cylinders = 0;
	scene.cone = add_cone();
	scene.cones = 0;
	scene.figures = scene.planes + scene.spheres + \
	scene.cylinders + scene.cones;
	scene.light = light2();
	scene.sources = 2;
	scene.recursion_depth = 4;
	draw_scene(win, scene);
}
