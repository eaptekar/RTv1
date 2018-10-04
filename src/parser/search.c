#include "rtv1.h"
#include "parser.h"

//just for debug
#include <stdio.h>

int get_int_value(char* line)
{
    return ft_atoi(line);
}

t_vector* get_vector(char* line)
{
    t_vector *vector = (t_vector*)malloc(sizeof(t_vector));      
    char buff[10];
    double *axis;

    axis = (double*)vector;
    while (*line)
    {
        cut_to_num(buff, line);
        if (*buff)
            *axis++ = ft_atof(buff);
        while (*line != ' ' && *line)
            ++line;
        if (!(*line))
            return vector;
        ++line;
    }

    return vector;
}

int find_value(char* cursor, char* buff, char* value)
{
    char line[LINE_BUFF_SIZE];

    while (*cursor != '}' && *cursor)
    {
        while (ft_isspase(*cursor))
            ++cursor;
        _getline(line, cursor);
        if (!ft_strncmp(line, value, ft_strlen(value)))
        {
            _getline(buff, line + ft_strlen(value)); 
            cut_br(buff);
            break;
        }
        cursor += ft_strlen(line);
    }
    if (!(*cursor) || *cursor == '}')
    {
        ft_putendl(value);
        ERROR(": not found");
    }
    return 0;
}
