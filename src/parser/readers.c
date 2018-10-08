/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:32:26 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/08 18:08:59 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	scene->recursion_depth = ft_atoi(FIND("recursion"));
	scene->win_w = ft_atoi(FIND("window_x"));
	scene->win_h = ft_atoi(FIND("window_y"));
	next_cbr(&cursor);
	return (cursor);
}

char	*reader_light(t_scene *scene, char *cursor)
{
	char	buff[LINE_BUFF_SIZE];
	t_light	*light;

	if (!(light = (t_light*)malloc(sizeof(t_light) + 1)))
		ERROR("malloc error: light");
	move_cursor(&cursor);
	light->type = ft_atoi(FIND("type"));
	if (light->type == 2)
		set_vval(&(light->ray), FIND("position"));
	if (light->type == 3)
		set_vval(&(light->ray), FIND("direction"));
	light->intensity = ft_atof(FIND("intensity"));
	next_cbr(&cursor);
	scene->light[scene->sources] = *light;
	scene->sources = scene->sources + 1;
	free(light);
	return (cursor);
}
