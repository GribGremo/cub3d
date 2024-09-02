/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:30:22 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/02 17:10:48 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	check_args(&data, argc, argv);
	filedup(&data, argv);
	parse_file(&data);
	check_close_map(&data, data.map->map);
	print_array(data.map->map);
	print_textures(&data);
	ft_free_all(&data);
}

/*Check number of arguments, file extension, and if the file is readable*/
void	check_args(t_data *data, int argc, char **argv)
{
	int	i;

	if (argc != 2)
		exit_error(data, "Invalid number of arguments", -1);
	i = ft_strlen(argv[1]);
	if (i < 5 || ft_strcmp(".cub", &argv[1][i - 4]) || !ft_isprint(argv[1][0]))
		exit_error(data, "Invalid filepath format", -1);
	if (!is_file_readable(argv[1]))
		exit_error(data, "Cannot open file", -1);
}

/*Exit program and print error message*/
void	exit_error(t_data *data, char *msg, int line)
{
	ft_putstr_fd("Error\n", 2);
	if (line > -1)
	{
		ft_putstr_fd("Line ", 2);
		ft_putnbr_fd(line, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(msg, 2);
	ft_free_all(data);
	exit(1);
}

/*Initalise data variables*/
void	init_data(t_data *data)
{
	data->n_tex = NULL;
	data->s_tex = NULL;
	data->e_tex = NULL;
	data->w_tex = NULL;
	data->f_tex = -1;
	data->c_tex = -1;
	data->file = NULL;
	data->player = malloc(sizeof(t_player));
	if (data->player == NULL)
		exit_error(data, "Memory allocation issue", -1);
	data->player->px = 0;
	data->player->py = 0;
	data->map = malloc(sizeof(t_map));
	if (data->map == NULL)
		exit_error(data, "Memory allocation issue", -1);
	data->map->map_x = 0;
	data->map->map_y = 0;
	data->map->map = NULL;
}
