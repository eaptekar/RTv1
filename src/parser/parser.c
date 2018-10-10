/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:09:39 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/10 20:14:28 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			check_reader(char *str, char **item_name)
{
	if (!ft_strncmp(*item_name, str, ft_strlen(str)))
	{
		*item_name += ft_strlen(str);
		return (1);
	}
	return (0);
}

t_scene		*new_scene(void)
{
	t_scene *scene;

	if (!(scene = (t_scene*)malloc(sizeof(t_scene))))
		ERROR("malloc error: scene");
	scene->planes = 0;
	scene->spheres = 0;
	scene->cylinders = 0;
	scene->cones = 0;
	scene->figures = 0;
	scene->sources = 0;
	if (!(scene->plane = (t_plane*)malloc(sizeof(t_plane) * DEFAULT_ITEMS)))
		ERROR("malloc error: scene->plane");
	if (!(scene->sphere = (t_sphere*)malloc(sizeof(t_sphere) * DEFAULT_ITEMS)))
		ERROR("malloc error: scene->sphere");
	if (!(scene->cylinder = (t_cylinder*)malloc(sizeof(t_cylinder) \
		* DEFAULT_ITEMS)))
		ERROR("malloc error: scene->cylinder");
	if (!(scene->cone = (t_cone*)malloc(sizeof(t_cone) * DEFAULT_ITEMS)))
		ERROR("malloc error: scene->cone");
	if (!(scene->light = (t_light*)malloc(sizeof(t_light) * DEFAULT_ITEMS)))
		ERROR("malloc error: scene->light");
	return (scene);
}

char		*(*get_reader(char **item_name))(t_scene *scene, char *cursor)
{
	while (ft_isspace(**item_name))
		++(*item_name);
	if (check_reader("scene", item_name))
		return (&reader_scene);
	if (check_reader("light", item_name))
		return (&reader_light);
	if (check_reader("plane", item_name))
		return (&reader_plane);
	if (check_reader("sphere", item_name))
		return (&reader_sphere);
	if (check_reader("cylinder", item_name))
		return (&reader_cylinder);
	if (check_reader("cone", item_name))
		return (&reader_cone);
	ERROR("scene syntax error");
	return (NULL);
}

t_scene		*parse_file(char *filename)
{
	char	file[FILE_BUFF_SIZE];
	int		fd;
	char	*cursor;
	t_scene	*scene;

	if ((fd = open(filename, O_RDONLY)) < 0)
		ERROR(strerror(errno));
	if ((read(fd, NULL, 0)) < 0)
		ERROR(strerror(errno));
	file[read(fd, file, FILE_BUFF_SIZE)] = '\0';
	cursor = file;
	if (!(*cursor))
		ERROR("empty file");
	scene = new_scene();
	while (*cursor)
	{
		cursor = get_reader(&cursor)(scene, cursor);
		while (*cursor && ft_isspace(*cursor))
			++cursor;
	}
	close(fd);
	if (!scene->win_w || !scene->figures || !scene->sources)
		ERROR("scene objects missing");
	return (scene);
}
