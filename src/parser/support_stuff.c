#include "rtv1.h"
#include "parser.h"

#include <stdio.h>

void print_vector(t_vector* t)
{
    printf("(%.1f,%.1f,%.1f)\n", t->x, t->y, t->z);
}

void print_scene(t_scene* scene)
{
    printf("position: ");
    print_vector(&scene->cam);
    printf("direction: ");
    print_vector(&scene->angle);
    printf("size %.0f x %.0f\n", scene->t_min, scene->t_max);
}

void _getline(char* buff, char* cursor)
{
    while (*cursor && *cursor != '\n')
        *buff++ = *cursor++;
    *buff = '\0';
}

void cut_br(char* line)
{
    while(*(++line) != ')')
        *(line - 1) = *line;
    *(line - 1) = '\0';
}

void cut_to_num(char* buff, char* line)
{
    while (*line && *line != ' ')
        *buff++ = *line++;
    *buff = '\0';
}

