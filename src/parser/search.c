/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:44:21 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/10 20:15:28 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_vector	*get_vector(char *line)
{
	t_vector	*vector;
	char		buff[10];
	int			n_shift;

	n_shift = 0;
	if (!(vector = (t_vector*)malloc(sizeof(t_vector) + 1)))
		ERROR("malloc error: get_vector");
	if ((n_shift = cut_to_num(buff, line)) == 0)
		ERROR("[get_vector:x] FLOAT expected");
	line += n_shift;
	vector->x = ft_atof(buff);
	if ((n_shift = cut_to_num(buff, line)) == 0)
		ERROR("[get_vector:y] FLOAT expected");
	line += n_shift;
	vector->y = ft_atof(buff);
	if ((n_shift = cut_to_num(buff, line)) == 0)
		ERROR("[get_vector:z] FLOAT expected");
	line += n_shift;
	vector->z = ft_atof(buff);
	return (vector);
}

char		*find_value(char *cursor, char *buff, char *value)
{
	char	line[LINE_BUFF_SIZE];
	char	*start;

	start = buff;
	while (*cursor != '}' && *cursor)
	{
		while (ft_isspace(*cursor))
			++cursor;
		get_line(line, cursor);
		if (!ft_strncmp(line, value, ft_strlen(value)))
		{
			get_line(buff, line + ft_strlen(value));
			if (cut_br(buff, value))
				ERROR(") expected ");
			break ;
		}
		if (*cursor == '}')
			break ;
		cursor += ft_strlen(line);
	}
	if (!(*cursor) || *cursor == '}')
		ERROR("object parameter is missing");
	return (start);
}
