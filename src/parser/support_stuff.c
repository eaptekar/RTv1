/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:44:09 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/08 17:03:10 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	get_line(char *buff, char *cursor)
{
	while (*cursor && *cursor != '\n')
		*buff++ = *cursor++;
	*buff = '\0';
}

void	cut_br(char *line)
{
	while (*(++line) != ')')
		*(line - 1) = *line;
	*(line - 1) = '\0';
}

void	cut_to_num(char *buff, char *line)
{
	while (*line && *line != ' ')
		*buff++ = *line++;
	*buff = '\0';
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
	while (**cursor != '}')
		++(*cursor);
	++(*cursor);
}
