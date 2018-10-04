#include "rtv1.h"
#include "parser.h"
#include <stdio.h>

void print_vector(t_vector* t)
{
    printf("(%.1f, %.1f, %.1f)\n", t->x, t->y, t->z);
}

void print_sphere(t_sphere *sphere)
{
    printf("\t\tposition: ");
    print_vector(&(sphere->center));
    printf("\t\tradius: %.1f\n", sphere->radius);
    printf("\t\tshine: %d\n", sphere->shine);
    printf("\t\tcolor: %d\n", sphere->color);
    printf("\t\treflection: %.1f\n", sphere->reflect);
}

void print_plane(t_plane *plane)
{
    printf("\t\tcenter: ");
    print_vector(&(plane->center));
    printf("\t\tnormal: ");
    print_vector(&(plane->normal));
    printf("\t\tshine: %d\n", plane->shine);
    printf("\t\tcolor: %d\n", plane->color);
    printf("\t\treflection: %.1f\n", plane->reflect);
}


void print_light(t_light *light)
{
    printf("\t\ttype: %d\n", light->type);
    printf("\t\tintensity: %.1f\n", light->intensity);
    printf("\t\tposition: ");
    print_vector(&(light->ray));
}

void print_scene(t_scene* scene)
{
    printf("Scene:\n");
    printf("position: ");
    print_vector(&scene->cam);
    printf("direction: ");
    print_vector(&scene->angle);
    printf("recursion: %d\n", scene->recursion_depth);
    printf("size [%.0fx%.0f]\n", scene->t_min, scene->t_max);
    printf("figures %d\n", scene->figures);
    printf("spheres %d\n\n", scene->spheres);
    for (int i = 0; i < scene->spheres; ++i)
    {
        printf("\tSphere %d\n", i);
        print_sphere(&(scene->sphere[i]));
    }
    printf("sources %d\n\n", scene->sources);
    for (int i = 0; i < scene->sources; ++i)
    {
        printf("\tSource %d\n", i);
        print_light(&(scene->light[i]));
    }
    printf("planes %d\n\n", scene->spheres);
    for (int i = 0; i < scene->sources; ++i)
    {
        printf("\tPlane %d\n", i);
        print_plane(&(scene->plane[i]));
    }
    printf("cylinders %d\n", scene->cylinders);
    printf("cones %d\n", scene->cones);
}

