#include "rtv1.h"
#include "parser.h"

#define FIND(X) find_value(++cursor, buff, X)
#define ADD_FIGURE(X) scene->X[scene->X##s] = *X;
#define INC_COUNTER(X) scene->X##s = scene->X##s + 1;
#define INC_FIGURES scene->figures = scene->figures + 1;
#define GET_NORM(X, Y) X->Y = get_normal(sub(X->Y, X->center));

void set_vval(t_vector *field, char* buff)
{
    t_vector *temp = NULL;

    temp = get_vector(buff);
    if (!temp)
        return;
    *field = *temp;
    free(temp);
}

char *reader_scene(t_scene* scene, char* cursor)
{
    char buff[LINE_BUFF_SIZE];

    move_cursor(&cursor);
    set_vval(&(scene->cam), FIND("position"));
    set_vval(&(scene->angle), FIND("direction"));
    scene->recursion_depth = ft_atoi(FIND("recursion")); 
    scene->win_w = ft_atoi(FIND("window_x")); 
    scene->win_h = ft_atoi(FIND("window_y")); 
    next_cbr(&cursor);
    return cursor;
}

char *reader_light(t_scene* scene, char* cursor)
{
    char buff[LINE_BUFF_SIZE];
    t_light *light = (t_light*)malloc(sizeof(t_light) + 1);

    move_cursor(&cursor);
    light->type = ft_atoi(FIND("type"));
    light->intensity = ft_atof(FIND("intensity"));
    if (light->type == 2)
        set_vval(&(light->ray), FIND("position"));
    if (light->type == 3)
        set_vval(&(light->ray), FIND("direction"));
    next_cbr(&cursor);
    scene->light[scene->sources] = *light;
    scene->sources = scene->sources + 1;
    free(light);
    return cursor;
}

char *reader_sphere(t_scene* scene, char* cursor)
{
    char buff[LINE_BUFF_SIZE];
    t_sphere *sphere = (t_sphere*)malloc(sizeof(t_sphere) + 1);

    move_cursor(&cursor);
    set_vval(&(sphere->center), FIND("position"));
    sphere->radius = ft_atof(FIND("radius"));
    sphere->color = hex_to_int(FIND("color"));
    sphere->shine = ft_atoi(FIND("shine"));
    sphere->reflect = ft_atoi(FIND("reflection"));
    next_cbr(&cursor);
    ADD_FIGURE(sphere);
    INC_COUNTER(sphere);
    INC_FIGURES
    free(sphere);
    return cursor;
}
char *reader_plane(t_scene* scene, char* cursor)
{
    char buff[LINE_BUFF_SIZE];
    t_plane *plane = (t_plane*)malloc(sizeof(t_plane) + 1);

    move_cursor(&cursor);
    set_vval(&(plane->center), FIND("position"));
    set_vval(&(plane->normal), FIND("direction"));
    GET_NORM(plane, normal)
    plane->shine = ft_atoi(FIND("shine"));
    plane->reflect = ft_atof(FIND("reflection"));
    plane->color = hex_to_int(FIND("color"));
    next_cbr(&cursor);
    ADD_FIGURE(plane)
    INC_COUNTER(plane)
    INC_FIGURES
    free(plane);
    return cursor;
}

char *reader_cylinder(t_scene* scene, char* cursor)
{
    char buff[LINE_BUFF_SIZE];
    t_cylinder *cylinder = (t_cylinder*)malloc(sizeof(t_cylinder) + 1);

    move_cursor(&cursor);
    set_vval(&(cylinder->center), FIND("position"));
    set_vval(&(cylinder->axis), FIND("direction"));
    GET_NORM(cylinder, axis)
    cylinder->shine = ft_atoi(FIND("shine"));
    cylinder->radius = ft_atof(FIND("radius"));
    cylinder->reflect = ft_atof(FIND("reflection"));
    cylinder->color = hex_to_int(FIND("color")); 
    next_cbr(&cursor);
    ADD_FIGURE(cylinder);
    INC_COUNTER(cylinder);
    INC_FIGURES
    free(cylinder);
    return cursor;
}

char *reader_cone(t_scene* scene, char* cursor)
{
    char buff[LINE_BUFF_SIZE];
    t_cone *cone = (t_cone*)malloc(sizeof(t_cone) + 1);

    move_cursor(&cursor);
    set_vval(&(cone->center), FIND("position"));
    set_vval(&(cone->axis), FIND("direction"));
    GET_NORM(cone, axis)
    cone->shine = ft_atoi(FIND("shine"));
    cone->reflect = ft_atof(FIND("reflection"));
    cone->color = hex_to_int(FIND("color")); 
    next_cbr(&cursor);
    ADD_FIGURE(cone);
    INC_COUNTER(cone);
    INC_FIGURES
    free(cone);
    return cursor;
}
#undef FIND
#undef ADD_FIGURE
#undef INC_COUNTER
#undef INC_FIGURES
#undef GET_NORM
