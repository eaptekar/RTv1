/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:32:26 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/10 19:38:56 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_scene(t_scene **scene)
{
	check_vector((*scene)->cam, "scene->cam");
	if ((*scene)->win_w < 320)
		(*scene)->win_w = 320;
	else if ((*scene)->win_w > 2260)
		(*scene)->win_w = 2260;
	if ((*scene)->win_h < 320)
		(*scene)->win_h = 320;
	else if ((*scene)->win_h > 1380)
		(*scene)->win_h = 1380;
	if ((*scene)->recursion_depth < 0)
		(*scene)->recursion_depth = 0;
	else if ((*scene)->recursion_depth > 20)
		(*scene)->recursion_depth = 20;
}

void	check_light(t_light **light)
{
	if ((*light)->type < 1 || (*light)->type > 3)
		ERROR("invalid light type");
	if ((*light)->intensity < 0)
		(*light)->intensity = 0;
	else if ((*light)->intensity > 20)
		(*light)->intensity = 20;
	if ((*light)->type == 2)
		check_vector((*light)->ray, "light->position");
	if ((*light)->type == 3)
		check_vector((*light)->ray, "light->direction");
}

void	set_vval(t_vector *field, char *buff)
{
	t_vector	*temp;

	temp = NULL;
	temp = get_vector(buff);
	if (!temp)
		return ;
	*field = *temp;
	free(temp);
}

char	*reader_scene(t_scene *scene, char *cursor)
{
	char	buff[LINE_BUFF_SIZE];

	move_cursor(&cursor);
	set_vval(&(scene->cam), FIND("position"));
	set_vval(&(scene->angle), FIND("direction"));
	scene->win_w = ft_atoi(FIND("window_x"));
	scene->win_h = ft_atoi(FIND("window_y"));
	scene->recursion_depth = ft_atoi(FIND("recursion"));
	check_scene(&scene);
	next_cbr(&cursor);
	return (cursor);
}

char	*reader_light(t_scene *scene, char *cursor)
{
	char	buff[LINE_BUFF_SIZE];
	t_light	*light;

	if (scene->sources >= DEFAULT_ITEMS)
		ERROR("number of sources bigger then DEFAULT_ITEMS");
	if (!(light = (t_light*)malloc(sizeof(t_light) + 1)))
		ERROR("malloc error: light");
	move_cursor(&cursor);
	light->type = ft_atoi(FIND("type"));
	if (light->type == 2)
		set_vval(&(light->ray), FIND("position"));
	if (light->type == 3)
		set_vval(&(light->ray), FIND("direction"));
	light->intensity = ft_atof(FIND("intensity"));
	check_light(&light);
	next_cbr(&cursor);
	scene->light[scene->sources] = *light;
	scene->sources = scene->sources + 1;
	free(light);
	return (cursor);
}
