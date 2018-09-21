/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_spheres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 17:18:47 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/21 17:44:38 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_plane		*add_plane(void)
{
	static t_plane		plane[1];

	plane[0] = init_plane(set_point(0, -1, 0), set_point(0, 0, 0));
	plane[0] = parse_plane(plane[0], 700, 0, 0xFFFF00);
	return (plane);
}

static t_sphere		*add_sphere(void)
{
	static t_sphere	sphere[3];

	sphere[0] = init_sphere(set_point(0, -1, 4), 1);
	sphere[0] = parse_sphere(sphere[0], 500, 0.1, 0xFF0000);
	sphere[1] = init_sphere(set_point(2, 0, 7), 1);
	sphere[1] = parse_sphere(sphere[1], -1, 0.6, 0x0000FF);
	sphere[2] = init_sphere(set_point(-1.5, -0.25, 5.5), 0.75);
	sphere[2] = parse_sphere(sphere[2], 1000, 0.3, 0x00FF00);
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

void				scene4(t_window *win)
{
	t_scene		scene;

	scene.cam = set_point(-0.5, 0.5, 0);
	scene.angle = set_point(5, 5, 0);
	scene.plane = add_plane();
	scene.planes = 1;
	scene.sphere = add_sphere();
	scene.spheres = 3;
	scene.cylinder = add_cylinder();
	scene.cylinders = 0;
	scene.cone = add_cone();
	scene.cones = 0;
	scene.figures = scene.planes + scene.spheres + \
	scene.cylinders + scene.cones;
	scene.light = light4();
	scene.sources = 3;
	scene.recursion_depth = 3;
	draw_scene(win, scene);
}
