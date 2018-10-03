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
    char* (*reader)(t_scene* scene, char* cursor);

    fd = open(filename, 'r');
    read(fd, file, FILE_BUFF_SIZE - 2);
    file[FILE_BUFF_SIZE - 1] = '\0';   
    
    printf("%d\n", !ft_strncmp("1234", "1235", 3));
    t_scene *scene = (t_scene*)malloc(sizeof(t_scene));
    reader = get_reader(file);
    reader(scene, "abc");
    printf("%d", scene->recursion_depth);
    close(fd);
    return scene;
}

char* (*get_reader(char* item_name))(t_scene*, char* cursor)
{
    while (isspase(*item_name))
        ++item_name;
    if (!ft_strncmp(item_name, "scene", 5))
        return &reader_scene;
    return NULL;
}

char *reader_scene(t_scene* scene, char* cursor)
{
    while (isspase(*cursor))
        ++cursor;
    scene->recursion_depth = 3;
    return NULL;
}
