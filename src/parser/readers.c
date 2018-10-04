#include "rtv1.h"
#include "parser.h"

//just for debug
#include <stdio.h>

void set_vval(t_vector *field, char* buff)
{
    t_vector *temp;
    temp = get_vector(buff);
    *field = *temp;
    free(temp);

}

char *reader_scene(t_scene* scene, char* cursor)
{
    char buff[80];

    while (ft_isspase(*cursor))
        ++cursor;
    if (*cursor != '{')
        ERROR("reader: bad data");

    find_value(++cursor, buff, "position");
    set_vval(&(scene->cam), buff);
    find_value(++cursor, buff, "direction");
    set_vval(&(scene->angle), buff);
    return cursor + ft_strlen(cursor);
}
