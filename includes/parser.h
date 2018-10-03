#ifndef PARSER_H
#define PARSER_H

#include "rtv1.h"

#define FILE_BUFF_SIZE 1000

t_scene* parse_file(char* filename);

//returns pointer to function to read item; 
char* (*get_reader(char* item_name))(t_scene* scene, char* cursor);

//readers
char* reader_scene(t_scene* scene, char* cursor);
#endif
