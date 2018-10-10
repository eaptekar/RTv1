/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:44:09 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/10 17:49:27 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	get_line(char *buff, char *cursor)
{
	while (*cursor && *cursor != '\n')
		*buff++ = *cursor++;
	*buff = '\0';
}

int		cut_br(char *line, char *value)
{
	int		state;

	state = 1;
	if (!ft_strncmp("color", value, 5))
		state = 0;
	if (*line != '(')
		ERROR("( expected");
	while (*(++line) != ')')
	{
		if(!*line)
			return (1);
		if (state && *line != ' ' && *line != '-' && *line != '.' && \
			!ft_isdigit(*line))
			ERROR("invalid parameter argument");
		*(line - 1) = *line;
	}
	*(line - 1) = '\0';
	return (0);
}


int	cut_to_num(char *buff, char *line)
{
	int		i;
	int		initial_shift;

	i = 0;
	initial_shift = 0;
	while (ft_isspace(*line))
	{
		initial_shift++;
		line++;
	}
	while (line[i] && line[i] != ' ' && i < 10)
	{
		if (line[i] != '-' && line[i] != '.' && !ft_isdigit(line[i]))
			ERROR("invalid vector argument");
		buff[i] = line[i];
		i++;
	}
	if ((i == 10) && (line[i] || line[i] != ' '))
		ERROR("[cut_to_num] Unexpected arguments size");
	buff[i] = '\0';
	return (i + initial_shift);
}

void	move_cursor(char **cursor)
{
	while (ft_isspace(**cursor))
		++(*cursor);
	if (**cursor != '{')
		ERROR("reader: bad data");
}

void	next_cbr(char **cursor)
{
	while (**cursor != '}'){
                if (!**cursor )
                    ERROR("[next_cbr] block } expected");
		++(*cursor);
        }
	++(*cursor);
}
