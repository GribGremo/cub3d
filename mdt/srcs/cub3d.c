#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	check_args(argc, argv);
	parse_mapfile(&data, argv);
	print_array(data.file);
	get_textures(&data, "");
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

void	parse_mapfile(t_data *data, char **argv)
{
	char	*buf;
	int		fd;

	buf = NULL;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		if (buf[0] != '\0')                 //
			buf[ft_strlen(buf) - 1] = '\0'; //
		data->file = add_str_to_array(data->file, buf);
		if (data->file == NULL) // free data->map?
			exit_error("Memory allocation issue", -1);
	}
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

void	get_textures(t_data *data)
{
	int	i;
	int	is_map;

	is_map = 0;
	i = 0;
	while (data->file[i] != NULL && (!data->n_tex || !data->s_tex || !data->e_tex
			|| !data->w_tex || !data->f_tex || !data->c_tex))
	{
		if (is_var_line(data, i) && is_map)
			exit_error("Invalid order line in file", i + 1);
		else if (is_map_line(data->file[i]) && !is_blank_line(data->file[i]))
			is_map = i;
		i++;
	}
    if (!data->n_tex || !data->s_tex || !data->e_tex
			|| !data->w_tex || !data->f_tex || !data->c_tex)
        exit_error("Missing value(s) in file", -1);
    while(data->file[is_map] != NULL)
    {

        is_map++;
    }
}
int	is_var_line(t_data *data, int i)
{
	if (ft_strstr(data->file[i], "NO"))
		get_texture_path(data, &data->n_tex, i, "NO");
	else if (ft_strstr(data->file[i], "SO"))
		get_texture_path(data, &data->s_tex, i, "SO");
	else if (ft_strstr(data->file[i], "WE"))
		get_texture_path(data, &data->w_tex, i, "WE");
	else if (ft_strstr(data->file[i], "EA"))
		get_texture_path(data, &data->e_tex, i, "EA");
	else if (ft_strstr(data->file[i], "F"))
		get_texture_path(data, &data->f_tex, i, "F");
	else if (ft_strstr(data->file[i], "C"))
		get_texture_path(data, &data->c_tex, i, "C");
	else if (is_blank_line(data->file[i]) || is_map_line(data->file[i]))
		return (0);
	else if (!is_map_line(data->file[i]))
		exit_error("Invalid format in file", i + 1);
	return (1);
}

void	get_texture_path(t_data *data, char **var, int i, char *cmp)
{
	int	j;

	(void)data; // Comment free en cas d'erreur? lst alloc?
	j = 0;
	if (*var != NULL)
		exit_error("Invalid value declaration in file: Value set-up twice", i + 1);
	while (data->file[i][j] == ' ')
		j++;
	if (ft_strncmp(&data->file[i][j], cmp, ft_strlen(cmp)))
		exit_error("Invalid value declaration in file: Identifier should be first in line", i + 1);
	j += ft_strlen(cmp);
	if (data->file[i][j] != ' ')
		exit_error("Invalid value declaration in file: Identifier and value must be separated", i + 1);
	while (data->file[i][j] == ' ')
		j++;
	if (data->file[i][j] == '\0')
		exit_error("Invalid value declaration in file: No value found on line", i + 1);
	*var = ft_strdup_l(&data->file[i][j], ' ');
	if (var == NULL)
		exit_error("Memory allocation issue", -1);
	j += ft_strlen(*var);
	while (data->file[i][j] == ' ')
		j++;
	if (data->file[i][j] != '\0')
		exit_error("Invalid value declaration in file: Multiple value on line", i + 1);
}

void get_rgb_value()
{
    int i;
    char *temp;

    temp = NULL;
    i = 0;
    while(str[i] != '\0')
    {
        if (!ft_isalpha(str[i] || str[i] != ','))
            exit_error("Invalid RGB declaration in file: Invalid character to declare RGB code");
        i++;
    }
    i = 0;
    temp = ft_strdup_l(str, ',')
    if (str[i] != ',')
        exit_error("Invalid RGB declaration in file: M")
}

char	*ft_strdup_l(char *str, char limit)
{
	int		i;
	int		size;
	char	*res;

	size = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != limit)
	{
		size++;
		i++;
	}
	res = malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != limit)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	is_blank_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			return (0);
	}
	return (1);
}
int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
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