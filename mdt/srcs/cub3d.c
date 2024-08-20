#include "cub3d.h"

int main(int argc, char **argv)
{
    t_data data;

    init_data(&data);
    check_args(argc, argv);
    parse_mapfile(&data, argv);
    print_array(data.map);
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
int is_file_readable(char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY); // A verifier pour les dossiers
    if (fd == -1)
        return (0);
    else 
    {
        close(fd);
        return (1);
    }
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
    }
}
void    print_array(char **array)
{
    int i;

    i = 0;
    if (!array)
        return ;
    while(array[i] != NULL)
    {
        printf("%s\n", array[i]);
        i++;
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
    int i;
    int j;

    j = 0;
    i = 0;
    while(data->map[i] != NULL)
    {
        while(data->map[i][j] != ' ' || data->map[i][j] != '\0')
            j++;
        if (!ft_strncmp(str, data->map[i][j], ft_strlen(str)))
        {
            i += ft_strlen(str);
            while(data->map[i][j] != ' ' || data->map[i][j] != '\0')
                j++;
        }
    }
}
int is_var_line(t_data *data, char *line)
{
    int i;

    i = 0;
    while(line[i] != '\0')
    {
        while(line[i] == ' ')
            i++;
        if (!ft_strncmp("NO",&line[i], 2))
            get_texture_path(data, data->n_tex, &line[i + 2]);
        else if (!ft_strncmp("SO",&line[i], 2))
            get_texture_path(data, data->s_tex, &line[i + 2]);
        else if (!ft_strncmp("WE",&line[i], 2))
            get_texture_path(data, data->w_tex, &line[i + 2]);
        else if (!ft_strncmp("EA",&line[i], 2))
            get_texture_path(data, data->e_tex, &line[i + 2]);
        else if (!ft_strncmp("F",&line[i], 1))
            get_texture_path(data, data->f_tex, &line[i + 1]);
        else if (!ft_strncmp("C",&line[i], 1))
            get_texture_path(data, data->c_tex, &line[i + 1]);
        i++;
    }
}

void get_texture_path(t_data *data, char *var, char *str)
{
    // int i;
    // int size;

    // size = 0;
    // i = 0;

    char **array;



    array = NULL;
    if(var != NULL)//
        exit_error("Texture set-up twice");//
    array = ft_split(str, ' ');
    if (ft_tablen(array) != 2)
        exit_error("Invalid format to declare texture path");
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