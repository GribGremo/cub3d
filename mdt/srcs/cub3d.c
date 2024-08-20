#include "cub3d.h"

int main(int argc, char **argv)
{
    t_data data;

    init_data(&data);
    check_args(argc, argv);
    parse_mapfile(&data, argv);
    print_array(data.map);
    get_textures(&data,"");
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
    while(data->map[i] != NULL)
    {
        is_var_line(data, data->map[i]);
        if (is_map_line(line))
            is_map = 1;
        i++;
    }
}
int is_var_line(t_data *data, char *line)
{
    int i;

    i = 0;
    // while(line[i] != '\0')
    // {
        // while(line[i] == ' ')
        //     i++;
        if (ft_strnstr(line, "NO", 2))//!ft_strncmp("NO",&line[i], 2))//ft_strchr?
            get_texture_path(data, data->n_tex, line, "NO");
        else if (ft_strnstr(line, "SO", 2))//!ft_strncmp("SO",&line[i], 2))
            get_texture_path(data, data->s_tex, line, "SO");
        else if (ft_strnstr(line, "WE", 2))//!ft_strncmp("WE",&line[i], 2))
            get_texture_path(data, data->w_tex, line, "WE");
        else if (ft_strnstr(line, "EA", 2))//!ft_strncmp("EA",&line[i], 2))
            get_texture_path(data, data->e_tex, line, "EA");
        else if (ft_strnstr(line, "F", 1))//!ft_strncmp("F",&line[i], 1))
            get_texture_path(data, data->f_tex, line, "F");
        else if (ft_strnstr(line, "C", 1))//!ft_strncmp("C",&line[i], 1))
            get_texture_path(data, data->c_tex, line, "C");
        else if (is_blank_line(line))
            return (0);
        else if (data->n_tex || data->s_tex || data->e_tex || data->w_tex || data->f_tex || data->c_tex)
            exit_error("Invalid format in file");
        // i++;
    // }
    return (0);
}

void get_texture_path(t_data *data, char *var, char *str, char *cmp)
{
    // int i;
    // int size;

    // size = 0;
    // i = 0;
    (void) data;
    char **array;

    array = NULL;
    if(var != NULL)//
        exit_error("Texture set-up twice");//
    array = ft_split(str, ' ');
    if (array == NULL)
        exit_error("Memory allocation issue");//A VOIR SPLIT
    // print_array(array);
    if (ft_tablen(array) < 2 && ft_strcmp(cmp, array[0]))
    {
        free_tab(array);
        exit_error("Invalid file format: Need space before texture path");
    }
    if (ft_tablen(array) > 2)
    {
        free_tab(array);
        exit_error("Invalid file format: Too many arguments to declare texture path");
    }
    if(!ft_strcmp(cmp,array[0]))
        var = ft_strdup(array[1]);
    // while(str[i] == ' ')
    //     i++;
    // while(str[i] != '\0' && str[i] != ' ')// POTENTIELLEMENT AUTRE CHOSE DERRIERE, ERREUR SI OUI
    // {
    //     size++;
    //     i++;
    // }
    // if (size == 0)
    //     exit_error("No value for texture");
    // var = malloc(sizeof(char) * size + 1);//
    // i -= size;
    // size = 0;
    // while(str[i] != '\0' && str[i] != ' ')
    // {
    //     var[size] = str[i];
    //     i++;
    //     size++;
    // }
    // var[size] = '\0';
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