#ifndef PARSER_H
#define PARSER_H

#include "rtv1.h"

#define DEFAULT_ITEMS 20
#define FILE_BUFF_SIZE 1000
#define LINE_BUFF_SIZE 80

t_scene* parse_file(char* filename);

//support stuff
int find_value(char* cursor, char* buff, char* value);
t_vector* get_vector(int dim, char* line);

//returns pointer to function to read item; 
char* (*get_reader(char** item_name))(t_scene* scene, char* cursor);

//readers
char* reader_scene(t_scene* scene, char* cursor);
char* reader_light(t_scene* scene, char* cursor);
char* reader_cylinder(t_scene* scene, char* cursor);
#endif
