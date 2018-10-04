#include "rtv1.h"
#include "parser.h"

//just for debug
#include <stdio.h>

void set_vval(t_vector *field, char* buff)
{
    t_vector *temp = NULL;

    temp = get_vector(buff);
    *field = *temp;
    free(temp);
}

char *reader_scene(t_scene* scene, char* cursor)
{
    char buff[LINE_BUFF_SIZE];

    while (ft_isspase(*cursor))
        ++cursor;
    if (*cursor != '{')
        ERROR("reader: bad data");

    find_value(++cursor, buff, "position");
    set_vval(&(scene->cam), buff);
    find_value(++cursor, buff, "direction");
    set_vval(&(scene->angle), buff);
    find_value(++cursor, buff, "recursion");
    scene->recursion_depth = ft_atoi(buff); 
    find_value(++cursor, buff, "window_x");
    scene->t_min = ft_atoi(buff); 
    find_value(++cursor, buff, "window_y");
    scene->t_max = ft_atoi(buff); 
    while (*cursor++ != '}')
        ;
    return cursor;
}

char *reader_sphere(t_scene* scene, char* cursor)
{
    char buff[LINE_BUFF_SIZE];
    t_sphere *sphere = (t_sphere*)malloc(sizeof(sphere));

    while (ft_isspase(*cursor))
        ++cursor;
    if (*cursor != '{')
        ERROR("reader: bad data");

    find_value(++cursor, buff, "position");
    set_vval(&(sphere->center), buff);
    find_value(++cursor, buff, "radius");
    sphere->radius = ft_atof(buff);
    find_value(++cursor, buff, "reflection");
    sphere->reflect = ft_atof(buff);
    while (*cursor++ != '}')
        ;
    scene->sphere[scene->spheres] = *sphere;
    scene->spheres = scene->spheres + 1;
    free(sphere);
    return cursor;
}
