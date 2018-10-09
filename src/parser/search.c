/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:44:21 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/09 18:59:31 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_vector	*get_vector(char *line)
{
	t_vector	*vector;
	char		buff[10];
	double		*axis;

	if (!(vector = (t_vector*)malloc(sizeof(t_vector) + 1)))
		ERROR("malloc error: get_vector");
	axis = (double*)vector;
	while (*line)
	{
		cut_to_num(buff, line);
		if (*buff)
			*axis++ = ft_atof(buff);
		while (*line != ' ' && *line)
			++line;
		if (!(*line))
			return (vector);
		++line;
	}
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
			cut_br(buff);
			break ;
		}
		if (*cursor == '}')
			break ;
		cursor += ft_strlen(line);
	}
	if (!(*cursor) || *cursor == '}')
	{
		ft_putstr(value);
		ERROR(" : not found");
	}
	return (start);
}
