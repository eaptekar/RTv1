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
    t_sphere *sphere = (t_sphere*)malloc(sizeof(sphere) + 1);

    while (ft_isspase(*cursor))
        ++cursor;
    if (*cursor != '{')
        ERROR("reader: bad data");

    find_value(++cursor, buff, "position");
    set_vval(&(sphere->center), buff);
    find_value(++cursor, buff, "radius");
    sphere->radius = ft_atof(buff);
    find_value(++cursor, buff, "color");
    sphere->color = ft_atoi(buff);
    find_value(++cursor, buff, "shine");
    sphere->shine = ft_atoi(buff);
    while (*cursor++ != '}')
        ;
    scene->sphere[scene->spheres] = *sphere;
    scene->spheres = scene->spheres + 1;
    free(sphere);
    return cursor;
}

char *reader_light(t_scene* scene, char* cursor)
{
    char buff[LINE_BUFF_SIZE];
    t_light *light = (t_light*)malloc(sizeof(t_light) + 1);

    while (ft_isspase(*cursor))
        ++cursor;
    if (*cursor != '{')
        ERROR("reader: bad data");

    find_value(++cursor, buff, "type");
    light->type = ft_atoi(buff);
    find_value(++cursor, buff, "intensity");
    light->intensity = ft_atoi(buff);
    if (light->type == 2)
    {
        find_value(++cursor, buff, "position");
        set_vval(&(light->ray), buff);

    }
    while (*cursor++ != '}')
        ;
    scene->light[scene->sources] = *light;
    scene->sources = scene->sources + 1;
    free(light);
    return cursor;
}
