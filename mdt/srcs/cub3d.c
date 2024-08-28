#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	check_args(argc, argv);
	filedup(&data, argv);
	parse_file(&data);
	print_array(data.map->map);
	ft_free_all(&data);
	// print_textures(&data);
}

void	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		exit_error("Invalid number of arguments", -1);
	i = ft_strlen(argv[1]);
	if (i < 5 || ft_strcmp(".cub", &argv[1][i - 4]) || !ft_isprint(argv[1][0]))
		exit_error("Invalid filepath format", -1);
	if (!is_file_readable(argv[1])) // does_file_exist?
		exit_error("Cannot open file", -1);
}

void	exit_error(char *msg, int line)
{
	printf("Error\n");
    if (line > -1)
        printf("Line %d: ", line);
    printf("%s",msg);
	exit(1);
}

void	init_data(t_data *data)
{
	data->n_tex = NULL;
	data->s_tex = NULL;
	data->e_tex = NULL;
	data->w_tex = NULL;
	data->f_tex = NULL;
	data->c_tex = NULL;
    data->file = NULL;
	data->map = malloc(sizeof(t_map));//
	if (data->map == NULL)
		exit_error("Memory allocation issue", - 1);
	data->map->map_x = 0;
	data->map->map_y = 0;
	data->map->map = NULL;

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