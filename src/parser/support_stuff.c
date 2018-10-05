#include "rtv1.h"
#include "parser.h"

void _getline(char* buff, char* cursor)
{
    while (*cursor && *cursor != '\n')
        *buff++ = *cursor++;
    *buff = '\0';
}

void cut_br(char* line)
{
    while(*(++line) != ')')
        *(line - 1) = *line;
    *(line - 1) = '\0';
}

void cut_to_num(char* buff, char* line)
{
    while (*line && *line != ' ')
        *buff++ = *line++;
    *buff = '\0';
}

void move_cursor(char **cursor)
{
    while (ft_isspase(**cursor))
        ++(*cursor);
    if (**cursor != '{')
        ERROR("reader: bad data");
}

void next_cbr(char **cursor)
{
    while (**cursor != '}')
        ++(*cursor);
    ++(*cursor);
}

