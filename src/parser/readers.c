#include "rtv1.h"
#include "parser.h"

//just for debug
#include <stdio.h>

char *reader_scene(t_scene* scene, char* cursor)
{
    char buff[80];

    while (ft_isspase(*cursor))
        ++cursor;
    if (*cursor != '{')
        ERROR("reader: bad data");
    scene->recursion_depth = 3;
    find_value(++cursor, buff, "position");
    printf("%s\n", buff);
    return cursor + ft_strlen(cursor);
}
