#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	check_args(argc, argv);
	filedup(&data, argv);
	parse_file(&data);
	print_textures(&data);
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
	data->map = NULL;
}



// void get_rgb_value()
// {
//     int i;
//     char *temp;

//     temp = NULL;
//     i = 0;
//     while(str[i] != '\0')
//     {
//         if (!ft_isalpha(str[i] || str[i] != ','))
//             exit_error("Invalid RGB declaration in file: Invalid character to declare RGB code");
//         i++;
//     }
//     i = 0;
//     temp = ft_strdup_l(str, ',')
//     if (str[i] != ',')
//         exit_error("Invalid RGB declaration in file: M")
// }

/*
-Double declaration d'argument
ex:
NO toto.chemin
NO titi.chemin
||
NO
NO titi.chemin
*/