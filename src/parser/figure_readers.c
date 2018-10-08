/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_readers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:55:49 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/08 20:17:50 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*reader_plane(t_scene *scene, char *cursor)
{
	char	buff[LINE_BUFF_SIZE];
	t_plane	*plane;

	if (!(plane = (t_plane*)malloc(sizeof(t_plane) + 1)))
		ERROR("malloc error: plane");
	move_cursor(&cursor);
	set_vval(&(plane->center), FIND("position"));
	set_vval(&(plane->normal), FIND("direction"));
	GET_NORM(plane, normal);
	plane->shine = ft_atoi(FIND("shine"));
	plane->reflect = ft_atof(FIND("reflection"));
	plane->color = hex_to_int(FIND("color"));
	next_cbr(&cursor);
	scene->plane[scene->planes] = *plane;
	scene->planes = scene->planes + 1;
	scene->figures = scene->figures + 1;
	free(plane);
	return (cursor);
}

char	*reader_sphere(t_scene *scene, char *cursor)
{
	char		buff[LINE_BUFF_SIZE];
	t_sphere	*sphere;

	if (!(sphere = (t_sphere*)malloc(sizeof(t_sphere) + 1)))
		ERROR("malloc error: sphere");
	move_cursor(&cursor);
	set_vval(&(sphere->center), FIND("position"));
	sphere->radius = ft_atof(FIND("radius"));
	sphere->color = hex_to_int(FIND("color"));
	sphere->shine = ft_atoi(FIND("shine"));
	sphere->reflect = ft_atof(FIND("reflection"));
	next_cbr(&cursor);
	scene->sphere[scene->spheres] = *sphere;
	scene->spheres = scene->spheres + 1;
	scene->figures = scene->figures + 1;
	free(sphere);
	return (cursor);
}

char	*reader_cylinder(t_scene *scene, char *cursor)
{
	char		buff[LINE_BUFF_SIZE];
	t_cylinder	*cylinder;

	if (!(cylinder = (t_cylinder*)malloc(sizeof(t_cylinder) + 1)))
		ERROR("malloc error: cylinder");
	move_cursor(&cursor);
	set_vval(&(cylinder->center), FIND("position"));
	set_vval(&(cylinder->axis), FIND("direction"));
	GET_NORM(cylinder, axis);
	cylinder->shine = ft_atoi(FIND("shine"));
	cylinder->radius = ft_atof(FIND("radius"));
	cylinder->reflect = ft_atof(FIND("reflection"));
	cylinder->color = hex_to_int(FIND("color"));
	next_cbr(&cursor);
	scene->cylinder[scene->cylinders] = *cylinder;
	scene->cylinders = scene->cylinders + 1;
	scene->figures = scene->figures + 1;
	free(cylinder);
	return (cursor);
}

char	*reader_cone(t_scene *scene, char *cursor)
{
	char	buff[LINE_BUFF_SIZE];
	t_cone	*cone;

	if (!(cone = (t_cone*)malloc(sizeof(t_cone) + 1)))
		ERROR("malloc error: cone");
	move_cursor(&cursor);
	set_vval(&(cone->center), FIND("position"));
	set_vval(&(cone->axis), FIND("direction"));
	GET_NORM(cone, axis);
	cone->k = ft_atof(FIND("angle"));
	cone->shine = ft_atoi(FIND("shine"));
	cone->reflect = ft_atof(FIND("reflection"));
	cone->color = hex_to_int(FIND("color"));
	next_cbr(&cursor);
	scene->cone[scene->cones] = *cone;
	scene->cones = scene->cones + 1;
	scene->figures = scene->figures + 1;
	free(cone);
	return (cursor);
}
