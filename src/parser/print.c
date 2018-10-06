#include "rtv1.h"
#include "parser.h"
#include <stdio.h>

#define PRINTI(X) printf("\t\t%s: %d\n", #X, item->X);
#define PRINTD(X) printf("\t\t%s: %.1f\n", #X, item->X);
#define PRINT_V(X) printf("\t\t%s: ", #X); print_vector(&(item->X));

#define DISPLAY(X) printf("%s %d\n\n", #X, scene->X##s);\
for (int i = 0; i < scene->X##s; ++i) \
{\
    printf("\t%s %d\n", #X, i);\
    print_##X(&(scene->X[i]));\
}

void print_vector(t_vector* t)
{
    printf("(%.1f, %.1f, %.1f)\n", t->x, t->y, t->z);
}

void print_sphere(t_sphere *item)
{
    PRINT_V(center);
    PRINTD(radius);
    PRINTI(color);
    PRINTI(shine);
    PRINTD(reflect);
}

void print_plane(t_plane *item)
{
    PRINT_V(center);
    PRINT_V(normal);
    PRINTI(color);
    PRINTI(shine);
    PRINTD(reflect);
}

void print_light(t_light *item)
{
    PRINTI(type);
    PRINTD(intensity);
    if (item->type == 2 || item->type == 3)
    {
        PRINT_V(ray);
    }
}

void print_cylinder(t_cylinder *item)
{
    PRINT_V(center);
    PRINT_V(axis);
    PRINTD(radius);
    PRINTI(color);
    PRINTI(shine);
    PRINTD(reflect);
}

void print_scene(t_scene* scene)
{
    printf("Scene:\n");
    printf("Scene:\n");
    printf("position: ");
    print_vector(&scene->cam);
    printf("direction: ");
    print_vector(&scene->angle);
    printf("recursion: %d\n", scene->recursion_depth);
    printf("size [%dx%d]\n", scene->win_w, scene->win_h);
    printf("figures %d\n", scene->figures);
    DISPLAY(sphere);
    DISPLAY(plane);
    DISPLAY(cylinder);
    printf("sources %d\n\n", scene->sources);
    for (int i = 0; i < scene->sources; ++i)
    {
        printf("\tSource %d\n", i);
        print_light(&(scene->light[i]));
    }
}

