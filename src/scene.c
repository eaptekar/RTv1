/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:57:26 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/12 20:29:49 by eaptekar         ###   ########.fr       */
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

t_sphere	*parse_spheres(void)
{
	static t_sphere		sphere[4];

	sphere[0].center.x = 0;
	sphere[0].center.y = -1;
	sphere[0].center.z = 4;
	sphere[0].radius = 1;
	sphere[0].shine = 500;
	sphere[0].reflect = 0.2;
	sphere[0].color = 0xFF0000;
	// sphere[1].center.x = 2;
	// sphere[1].center.y = 0;
	// sphere[1].center.z = 7;
	// sphere[1].radius = 1;
	// sphere[1].shine = -1;
	// sphere[1].reflect = 0.6;
	// sphere[1].color = 0x0000FF;
	// sphere[2].center.x = -1;
	// sphere[2].center.y = 0;
	// sphere[2].center.z = 5;
	// sphere[2].radius = 0.75;
	// sphere[2].shine = 1000;
	// sphere[2].reflect = 0.2;
	// sphere[2].color = 0x00FF00;
	// sphere[3].center.x = 0;
	// sphere[3].center.y = -5001;
	// sphere[3].center.z = 0;
	// sphere[3].radius = 5000;
	// sphere[3].shine = 700;
	// sphere[3].reflect = 0;
	// sphere[3].color = 0xFFFF00;	
	return (sphere);
}

t_plane		*add_plane(void)
{
	static t_plane		plane[2];

	plane[0].center.x = 0;
	plane[0].center.y = 0;
	plane[0].center.z = 5;
	plane[0].normal.x = 0;
	plane[0].normal.y = 1;
	plane[0].normal.z = 5;
	plane[0].normal = sub_vect(plane[0].normal, plane[0].center);
	plane[0].normal = get_normal(plane[0].normal);
	plane[0].shine = -1;
	plane[0].reflect = 0;
	plane[0].color = 0xFFFF00;
	printf("%f %f %f\n", plane[0].normal.x, plane[0].normal.y, plane[0].normal.z);
	return (plane);
}

void		parse_figures(t_window *win)
{
	t_vector	cam;
	t_light		*light;
	t_figure	figure;

	win->figures = 2;
	win->recursion_depth = 3;
	cam = parse_camera();
	figure.sphere = parse_spheres();
	figure.plane = add_plane();
	figure.spheres = 1;
	figure.planes = 1;
	light = add_light(win);
	draw_figure(win, cam, figure, light);
}
