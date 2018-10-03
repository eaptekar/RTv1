#include "rtv1.h"
#include "parser.h"

#include <stdio.h>

int isspase(char c)
{
    return (c == '\t' || c == ' ' || c == '\n');
}

t_scene* parse_file(char* filename)
{
    char file[FILE_BUFF_SIZE];
    int fd;
    fd = open(filename, 'r');
    read(fd, file, FILE_BUFF_SIZE - 2);
    file[FILE_BUFF_SIZE - 1] = '\0';    
    printf("%s", file);
    t_scene *scene = (t_scene*)malloc(sizeof(t_scene));
    close(fd);
    return scene;
}

char* (*get_reader(char* item_name))(t_scene*, char* cursor)
{
    while (isspase(*item_name))
        ++item_name;
    if (!ft_strcmp(item_name, "scene"))
        return NULL;
    return NULL;
}

char *reader_scene(t_scene* scene, char* cursor)
{
    while (isspase(*cursor))
        ++cursor;
    scene->recursion_depth = 3;
    return NULL;
}
