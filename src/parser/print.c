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

void print_cylinder(t_cylinder *item)
{
    PRINT_V(center);
    PRINT_V(axis);
    PRINTD(radius);
    PRINTI(color);
    PRINTI(shine);
    PRINTD(reflect);
}

void print_cone(t_cone *item)
{
    PRINT_V(center);
    PRINT_V(axis);
    PRINTD(k);
    PRINTI(color);
    PRINTI(shine);
    PRINTD(reflect);
}

void print_scene(t_scene* scene)
{
    int sources = 0;

    printf("scene\n\tposition(%.2f %.2f %.2f)\n", scene->cam.x, scene->cam.y, scene->cam.z);
    printf("\tdirection(%.2f %.2f %.2f)\n", scene->angle.x, scene->angle.y, scene->angle.z);
    printf("\tsize [%dx%d]\n", scene->win_w, scene->win_h);
    printf("recursion(%d)\n", scene->recursion_depth);
    printf("sources %d\nfigures %d\n", scene->sources, scene->figures);
    while (sources < scene->sources)
    {
        printf("light\n");
        printf("\ttype(%d)\n\tintensity(%.2f)\n", scene->light[sources].type, scene->light[sources].intensity); 
        if (scene->light[sources].type != 1)
            printf("\tvector(%.f %.f %.f)\n", scene->light[sources].ray.x, scene->light[sources].ray.y, scene->light[sources].ray.z);
        sources++;        
    }
    DISPLAY(plane);
    DISPLAY(sphere);
    DISPLAY(cylinder);
    DISPLAY(cone); 
}
