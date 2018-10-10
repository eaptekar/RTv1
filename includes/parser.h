/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:41:51 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/10 19:54:14 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "rtv1.h"

# define DEFAULT_ITEMS	20
# define FILE_BUFF_SIZE	5000
# define LINE_BUFF_SIZE	80

# define FIND(X)			find_value(++cursor, buff, X)
# define GET_NORM(X, Y)		X->Y = get_normal(sub(X->Y, X->center));

void		get_line(char *line, char *cursor);
int			cut_to_num(char *buff, char *line);
int			cut_br(char *line, char *value);
void		move_cursor(char **cursor);
void		next_cbr(char **cursor);

char		*find_value(char *cursor, char *buff, char *value);
t_vector	*get_vector(char *line);

t_scene		*new_scene(void);
void		set_vval(t_vector *field, char *buff);
void		check_vector(t_vector vec, char *value);
void		check_plane(t_plane **plane);
void		check_sphere(t_sphere **sphere);
void		check_cylinder(t_cylinder **cylinder);
void		check_cone(t_cone **cone);

char		*reader_scene(t_scene *scene, char *cursor);
char		*reader_sphere(t_scene *scene, char *cursor);
char		*reader_light(t_scene *scene, char *cursor);
char		*reader_plane(t_scene *scene, char *cursor);
char		*reader_cylinder(t_scene *scene, char *cursor);
char		*reader_cone(t_scene *scene, char *cursor);

#endif
