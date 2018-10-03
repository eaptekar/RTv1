#include "rtv1.h"
#include "parser.h"

#include <stdio.h>

void _getline(char* buff, char* cursor)
{
    while (*cursor && *cursor != '\n')
        *buff++ = *cursor++;
    *buff = '\0';
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

