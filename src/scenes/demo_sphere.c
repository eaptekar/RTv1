/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:50:33 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/23 15:46:05 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_plane		*add_plane(void)
{
	static t_plane		plane[1];

	plane[0] = init_plane(set_point(0, -1, 0), set_point(0, 0, 0));
	plane[0] = parse_plane(plane[0], 400, 0, 0x808080);
	return (plane);
}

static t_sphere		*add_sphere(void)
{
	static t_sphere	sphere[1];

	sphere[0] = init_sphere(set_point(0, 1, 5), 1);
	sphere[0] = parse_sphere(sphere[0], 1000, 0, 0xFF0000);
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

void				scene1(t_window *win)
{
	t_scene		scene;

	scene.cam = set_point(0, 0.5, 0);
	scene.angle = set_point(0, 0, 0);
	scene.plane = add_plane();
	scene.planes = 1;
	scene.sphere = add_sphere();
	scene.spheres = 1;
	scene.cylinder = add_cylinder();
	scene.cylinders = 0;
	scene.cone = add_cone();
	scene.cones = 0;
	scene.figures = scene.planes + scene.spheres + \
	scene.cylinders + scene.cones;
	scene.light = light1();
	scene.sources = 1;
	scene.recursion_depth = 0;
	draw_scene(win, scene);
}
