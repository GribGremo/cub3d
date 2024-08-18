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
    int i;

    i = 0;
    buf = NULL;
    fd = open(argv[1], O_RDONLY);
    while(1)
    {
        buf = get_next_line(fd);
        if(buf == NULL)
            break;
        data->map = add_str_to_array(data->map, buf);
    }
    // print_array(data->map);
}
void    print_array(char **array)
{
    int i;

    i = 0;
    while(array || array[i] != NULL)
    {
        printf("%s\n", array[i]);
        i++;
    }
}

void init_data(t_data *data)
{
    data->north_texture = NULL;
    data->south_texture = NULL;
    data->east_texture = NULL;
    data->west_texture = NULL;
    data->floor_texture = NULL;
    data->ceiling_texture = NULL;
    data->map = NULL;
}