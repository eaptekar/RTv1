#include "rtv1.h"
#include "parser.h"

//just for debug
#include <stdio.h>

t_scene* parse_file(char* filename)
{
    char file[FILE_BUFF_SIZE];
    int fd;
    char* cursor;

    fd = open(filename, 'r');
    read(fd, file, FILE_BUFF_SIZE - 2);
    file[FILE_BUFF_SIZE - 1] = '\0';   
    cursor = file; 
    t_scene *scene = (t_scene*)malloc(sizeof(t_scene));
    cursor = get_reader(&cursor)(scene, cursor);
    printf("%d", scene->recursion_depth);
    close(fd);
    return scene;
}

char* (*get_reader(char** item_name))(t_scene*, char* cursor)
{
    while (ft_isspase(**item_name))
        ++(*item_name);
    if (!ft_strncmp(*item_name, "scene", 5))
    {
        *item_name += 5;
        return &reader_scene;
    }
    return NULL;
}
