#include "cub3d.h"

int main(int argc, char **argv)
{
    t_data data;

    init_data(&data);
    check_args(argc, argv);
    parse_mapfile(&data, argv);
    print_array(data.map);
    get_textures(&data,"");
    print_textures(&data);
}

void check_args(int argc, char **argv)
{
    int i;

    if (argc != 2)
        exit_error("Invalid number of arguments");
    i = ft_strlen(argv[1]);
    if (i < 5 || ft_strcmp(".cub", &argv[1][i - 4]) || !ft_isprint(argv[1][0]))
        exit_error("Invalid file format");
    if (!is_file_readable(argv[1]))//does_file_exist?
        exit_error("Cannot open file");
}

void exit_error(char *msg)
{
    printf("Error\n%s", msg);
    exit(1);
}


void parse_mapfile(t_data *data, char **argv)
{
    char *buf;
    int fd;

    buf = NULL;
    fd = open(argv[1], O_RDONLY);
    while(1)
    {
        buf = get_next_line(fd);
        if(buf == NULL)
            break;
        if (buf[0] != '\0')//
            buf[ft_strlen(buf) - 1] = '\0';//
        data->map = add_str_to_array(data->map, buf);
        if (data->map == NULL)//free data->map?
            exit_error("Memory allocation issue");
    }
}


void init_data(t_data *data)
{
    data->n_tex = NULL;
    data->s_tex = NULL;
    data->e_tex = NULL;
    data->w_tex = NULL;
    data->f_tex = NULL;
    data->c_tex = NULL;
    data->map = NULL;
}

void    get_textures(t_data *data, char *str)
{
    (void) str;
    int i;
    int j;
    int is_map;

    is_map = 0;
    j = 0;
    i = 0;
    while(data->map[i] != NULL && (!data->n_tex || !data->s_tex || !data->e_tex || !data->w_tex || !data->f_tex || !data->c_tex))
    {
        if (is_var_line(data, data->map[i]) && is_map_line(data->map[i]) == 1)
            exit_error("Invalid order line in file");
        // else if (is_map_line(data->map[i]) && !is_blank_line(data->map[i]))
        //     is_map = 1;
        i++;
    }
}
int is_var_line(t_data *data, char *line)
{
    int i;

    i = 0;
    if (ft_strnstr(line, "NO", 2))//strstr?
        get_texture_path(data, &data->n_tex, line, "NO");
    else if (ft_strnstr(line, "SO", 2))
        get_texture_path(data, &data->s_tex, line, "SO");
    else if (ft_strnstr(line, "WE", 2))
        get_texture_path(data, &data->w_tex, line, "WE");
    else if (ft_strnstr(line, "EA", 2))
        get_texture_path(data, &data->e_tex, line, "EA");
    else if (ft_strnstr(line, "F", 1))
        get_texture_path(data, &data->f_tex, line, "F");
    else if (ft_strnstr(line, "C", 1))
        get_texture_path(data, &data->c_tex, line, "C");
    else if (is_blank_line(line))
        return (0);
    else if (data->n_tex || data->s_tex || data->e_tex || data->w_tex || data->f_tex || data->c_tex)
        exit_error("Invalid format in file");
    return (1);
}

void get_texture_path(t_data *data, char **var, char *str, char *cmp)
{
    (void) data;//Comment free en cas d'erreur? lst alloc?
    int i;

    i = 0;
    if (*var != NULL)
        exit_error("Invalid texture path declaration in file: Texture path set-up twice");
    while(str[i] == ' ')
        i++;
    if(ft_strncmp(&str[i], cmp, ft_strlen(cmp)))
        exit_error("Invalid texture path declaration in file: Texture identifier should be first in line");
    i += ft_strlen(cmp);
    while(str[i] == ' ')
        i++;
    if (str[i] == '\0')
        exit_error("Invalid texture path declaration in file: No path found on line");
    *var = ft_strdup_l(&str[i], ' ');
    if (var == NULL)
        exit_error("Memory allocation issue");
    i += ft_strlen(*var);
    while(str[i] == ' ')
        i++;
    if (str[i] != '\0')
        exit_error("Invalid texture path declaration in file: Multiple value on line");
}

// void get_rgb_value()
// {
//     int i;
//     char *temp;

//     temp = NULL;
//     i = 0;
//     while(str[i] != '\0')
//     {
//         if (!ft_isalpha(str[i] || str[i] != ' ' || str[i] != ','))
//             exit_error("Invalid RGB declaration in file: Invalid character to declare RGB code");
//         i++;
//     }
//     i = 0;
//     temp = ft_strdup_l(str, ',')
//     if (str[i] != ',')
//         exit_error("Invalid RGB declaration in file: M")
// }

char *ft_strdup_l(char *str, char limit)
{
    int i;
    int size;
    char *res;

    size = 0;
    i = 0;
    while(str[i] != '\0' && str[i] != limit)
    {
        size++;
        i++;
    }
    res = malloc(sizeof(char) * (size + 1));
    if (res == NULL)
        return (NULL);
    i = 0;
    while(str[i] != '\0' && str[i] != limit)
    {
        res[i] = str[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}


int is_blank_line(char *line)
{
    int i;

    i = 0;
    while(line[i] != '\0')
    {
        if (line[i] != ' ')
            return (0);
    }
    return (1);
}
int is_map_line(char *line)
{
    int i;

    i = 0;
    while(line[i] != '\0')
    {
        if (line[i] != ' ' || line[i] != '0' || line[i] != '1' || line[i] != 'N' || line[i] != 'S' || line[i] != 'E' || line[i] != 'W')
            return (0);
        i++;
    }
    return (1);
}
/*
-Double declaration d'argument
ex:
NO toto.chemin
NO titi.chemin
||
NO
NO titi.chemin
*/