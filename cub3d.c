#include "cub3d.h"

int main(int argc, char **argv)
{
    check_args(argv);
    parse_mapfile(argv);
}

void check_args(int argc, char **argv)
{
    int i;

    if (argc != 2)
        exit_error("Invalid number of arguments");
    i = ft_strlen(argv[1]);
    if (i < 5 || ft_strcmp(".cub", argv[1][i - 4]) || !ft_isprint(argv[1][0]))
        exit_error("Invalid file format");
}