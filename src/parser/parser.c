#include "rtv1.h"
#include "parser.h"

#define LEN(X) ft_strlen(X)
#define CHECK(X) !ft_strncmp(*item_name, X, LEN(X)) && (*item_name += LEN(X))
#define RET_READER(X) return &reader_##X
#define ALLOC_ARR(X) (t_##X*)malloc(sizeof(t_##X) * DEFAULT_ITEMS)

t_scene* new_scene(void);

t_scene* parse_file(char* filename)
{
    char file[FILE_BUFF_SIZE];
    int fd;
    char* cursor;
    t_scene* scene;

    if ((fd = open(filename, O_RDONLY)) < 0)
    {
        ft_putendl(ft_itoa(fd));
        ERROR("failed to open scene file");
    }
    file[read(fd, file, FILE_BUFF_SIZE)] = '\0';   
    cursor = file; 
    scene = new_scene();
    while (*cursor)
    {
        cursor = get_reader(&cursor)(scene, cursor);
        while (*cursor && ft_isspase(*cursor))
            ++cursor;
    }
    close(fd);
    return scene;
}

char* (*get_reader(char** item_name))(t_scene*, char* cursor)
{
    while (ft_isspase(**item_name))
        ++(*item_name);
    if (CHECK("scene"))
        RET_READER(scene);
    if (CHECK("sphere"))
        RET_READER(sphere);
    if (CHECK("light"))
        RET_READER(light);
    if (CHECK("plane"))
        RET_READER(plane);
    if (CHECK("cylinder"))
        RET_READER(cylinder);
    ft_putendl("no reader found"); 
    ERROR(*item_name);
    return NULL;
}

t_scene* new_scene(void)
{
    t_scene *scene;
       
    scene = (t_scene*)malloc(sizeof(t_scene));
    scene->plane = ALLOC_ARR(plane);
    scene->sphere = ALLOC_ARR(sphere);
    scene->cylinder = ALLOC_ARR(cylinder);
    scene->cone = ALLOC_ARR(cone);
    scene->light = ALLOC_ARR(light);
    return scene;
}

#undef LEN 
#undef CHECK
#undef RET_READER
#undef ALLOC_ARR
