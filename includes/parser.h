/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:41:51 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/06 13:49:54 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "rtv1.h"

# define DEFAULT_ITEMS 20
# define FILE_BUFF_SIZE 5000
# define LINE_BUFF_SIZE 80

t_scene* parse_file(char* filename);

//support stuff
void _getline(char* line, char* cursor);
void cut_to_num(char* buff, char* line);
void cut_br(char* line);
void move_cursor(char **cursor);
void next_cbr(char **cursor);

//print
void print_vector(t_vector* t);
void print_scene(t_scene* scene);

//search
char* find_value(char* cursor, char* buff, char* value);
int get_int_value(char* line);
t_vector* get_vector(char* line);

//returns pointer to function to read item; 
char* (*get_reader(char** item_name))(t_scene* scene, char* cursor);

//readers
char* reader_scene(t_scene* scene, char* cursor);
char* reader_sphere(t_scene* scene, char* cursor);
char* reader_light(t_scene* scene, char* cursor);
char* reader_plane(t_scene* scene, char* cursor);
char* reader_cylinder(t_scene* scene, char* cursor);
char* reader_cone(t_scene* scene, char* cursor);

#endif
