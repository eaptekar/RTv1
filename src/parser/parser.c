#include "rtv1.h"
#include "parser.h"

#include <stdio.h>

t_scene* new_scene(void);

t_scene* parse_file(char* filename)
{
    char file[FILE_BUFF_SIZE];
    int fd;
    char* cursor;
    t_scene* scene;

    if ((fd = open(filename, O_RDONLY)) < 0)
    {
        ft_putendl(ft_itoa(fd));
        ERROR("failed to open scene file");
    }
    file[read(fd, file, FILE_BUFF_SIZE)] = '\0';   
    cursor = file; 
    scene = new_scene();
    while (*cursor)
    {
        cursor = get_reader(&cursor)(scene, cursor);
        while (*cursor && ft_isspase(*cursor))
            ++cursor;
    }
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
    if (!ft_strncmp(*item_name, "sphere", 6))
    {
        *item_name += 6;
        return &reader_sphere;
    }
    ft_putendl("no reader found"); 
    ERROR(*item_name);
    return NULL;
}

t_scene* new_scene(void)
{
    t_scene *scene;
       
    scene = (t_scene*)malloc(sizeof(t_scene));
    scene->plane = (t_plane*)malloc(sizeof(t_plane) * DEFAULT_ITEMS);
    scene->sphere = (t_sphere*)malloc(sizeof(t_sphere) * DEFAULT_ITEMS);
    scene->cylinder = (t_cylinder*)malloc(sizeof(t_cylinder) * DEFAULT_ITEMS);
    scene->cone = (t_cone*)malloc(sizeof(t_cone) * DEFAULT_ITEMS);
    scene->light = (t_light*)malloc(sizeof(t_light) * DEFAULT_ITEMS);
    return scene;
}


