/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_readers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:55:49 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/10 19:34:53 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		check_norm(t_vector vec1, t_vector vec2)
{
	if (vec1.x == vec2.x && vec1.y == vec2.y && vec1.z == vec2.z)
		ERROR("invalid figure direction parameters");
	return (1);
}

char	*reader_plane(t_scene *scene, char *cursor)
{
	char	buff[LINE_BUFF_SIZE];
	t_plane	*plane;

	if (scene->planes >= DEFAULT_ITEMS)
		ERROR("number of planes is bigger then DEFAULT_ITEMS");
	if (!(plane = (t_plane*)malloc(sizeof(t_plane) + 1)))
		ERROR("malloc error: plane");
	move_cursor(&cursor);
	set_vval(&(plane->center), FIND("position"));
	set_vval(&(plane->normal), FIND("direction"));
	if (check_norm(plane->center, plane->normal))
		GET_NORM(plane, normal);
	plane->shine = ft_atoi(FIND("shine"));
	plane->reflect = ft_atof(FIND("reflection"));
	if (!ft_iscolor(FIND("color")))
		ERROR("wrong color format");
	plane->color = hex_to_int(buff);
	check_plane(&plane);
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

	if (scene->spheres >= DEFAULT_ITEMS)
		ERROR("number of spheres is bigger then DEFAULT_ITEMS");
	if (!(sphere = (t_sphere*)malloc(sizeof(t_sphere) + 1)))
		ERROR("malloc error: sphere");
	move_cursor(&cursor);
	set_vval(&(sphere->center), FIND("position"));
	sphere->radius = ft_atof(FIND("radius"));
	sphere->shine = ft_atoi(FIND("shine"));
	sphere->reflect = ft_atof(FIND("reflection"));
	if (!ft_iscolor(FIND("color")))
		ERROR("wrong color format");
	sphere->color = hex_to_int(buff);
	check_sphere(&sphere);
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

	if (scene->cylinders >= DEFAULT_ITEMS)
		ERROR("number of cylinders is bigger then DEFAULT_ITEMS");
	if (!(cylinder = (t_cylinder*)malloc(sizeof(t_cylinder) + 1)))
		ERROR("malloc error: cylinder");
	move_cursor(&cursor);
	set_vval(&(cylinder->center), FIND("position"));
	set_vval(&(cylinder->axis), FIND("direction"));
	if (check_norm(cylinder->center, cylinder->axis))
		GET_NORM(cylinder, axis);
	cylinder->radius = ft_atof(FIND("radius"));
	cylinder->shine = ft_atoi(FIND("shine"));
	cylinder->reflect = ft_atof(FIND("reflection"));
	if (!ft_iscolor(FIND("color")))
		ERROR("wrong color format");
	cylinder->color = hex_to_int(buff);
	check_cylinder(&cylinder);
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

	if (scene->cones >= DEFAULT_ITEMS)
		ERROR("number of cones is bigger then DEFAULT_ITEMS");
	if (!(cone = (t_cone*)malloc(sizeof(t_cone) + 1)))
		ERROR("malloc error: cone");
	move_cursor(&cursor);
	set_vval(&(cone->center), FIND("position"));
	set_vval(&(cone->axis), FIND("direction"));
	if (check_norm(cone->center, cone->axis))
		GET_NORM(cone, axis);
	cone->k = ft_atof(FIND("angle"));
	cone->shine = ft_atoi(FIND("shine"));
	cone->reflect = ft_atof(FIND("reflection"));
	if (!ft_iscolor(FIND("color")))
		ERROR("wrong color format");
	cone->color = hex_to_int(buff);
	check_cone(&cone);
	next_cbr(&cursor);
	scene->cone[scene->cones] = *cone;
	scene->cones = scene->cones + 1;
	scene->figures = scene->figures + 1;
	free(cone);
	return (cursor);
}
