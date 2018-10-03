#include "rtv1.h"
#include "parser.h"

//just for debug
#include <stdio.h>

char *reader_scene(t_scene* scene, char* cursor)
{
//    char buff[80];

    while (ft_isspase(*cursor))
        ++cursor;
    printf("%c\n", *cursor);
    if (*cursor != '{')
        ERROR("err");
    scene->recursion_depth = 3;
    return cursor;
}
