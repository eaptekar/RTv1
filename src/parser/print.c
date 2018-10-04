#include "rtv1.h"
#include "parser.h"
#include <stdio.h>

void print_vector(t_vector* t)
{
    printf("(%.1f, %.1f, %.1f)\n", t->x, t->y, t->z);
}

void print_scene(t_scene* scene)
{
    printf("position: ");
    print_vector(&scene->cam);
    printf("direction: ");
    print_vector(&scene->angle);
    printf("recursion: %d\n", scene->recursion_depth);
    printf("size [%.0fx%.0f]\n", scene->t_min, scene->t_max);
    printf("spheres %d\n", scene->spheres);
    printf("cylinders %d\n", scene->cylinders);
    printf("cones %d\n", scene->cones);
    printf("planes %d\n", scene->planes);
}

