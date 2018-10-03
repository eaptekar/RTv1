#include "rtv1.h"
#include "parser.h"

#include <stdio.h>

void _getline(char* buff, char* cursor)
{
    while (ft_isspase(*cursor))
        ++cursor;
    while (*cursor && *cursor != '\n')
        *buff++ = *cursor++;
    *buff = '\0';
}

int find_value(char* cursor, char* buff, char* value)
{
    char line[LINE_BUFF_SIZE];

    while (*cursor)
    {
        _getline(line, cursor);
        if (ft_strncpy(line, value, ft_strlen(value)))
        {
            _getline(buff, line + ft_strlen(value)); 
            break;
        }
        cursor += ft_strlen(line);
    }
    return 0;
}

