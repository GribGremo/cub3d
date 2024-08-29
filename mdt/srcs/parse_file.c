/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:11:48 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/29 15:23:28 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	filedup(t_data *data, char **argv)
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
			exit_error(data, "Memory allocation issue", -1);
	}
}

void	parse_file(t_data *data)
{
	int	i;

	i = 0;
	while (data->file[i] != NULL && (!is_map_line(data->file[i])
			|| is_blank_line(data->file[i])))
	{
		get_file_value(data, i);
		i++;
	}
	if (!data->n_tex || !data->s_tex || !data->e_tex || !data->w_tex
		|| data->f_tex == -1 || data->c_tex == -1)
		exit_error(data, "Missing/Unorder value(s) in file", -1);
	if (data->file[i] == NULL)
		exit_error(data, "Missing map in file", -1);
	create_map(data, i);
	// print_array(data->map);
}

void	get_file_value(t_data *data, int i)
{
	char *temp;

	temp = NULL;
	if (ft_strstr(data->file[i], "NO"))
		parse_line_value(data, &data->n_tex, i, "NO");
	else if (ft_strstr(data->file[i], "SO"))
		parse_line_value(data, &data->s_tex, i, "SO");
	else if (ft_strstr(data->file[i], "WE"))
		parse_line_value(data, &data->w_tex, i, "WE");
	else if (ft_strstr(data->file[i], "EA"))
		parse_line_value(data, &data->e_tex, i, "EA");
	else if (ft_strstr(data->file[i], "F"))
	{
		parse_line_value(data, &temp, i, "F");
		data->f_tex = conv_int(data, temp);
		free(temp);
	}
	else if (ft_strstr(data->file[i], "C"))
	{
		parse_line_value(data, &temp, i, "C");
		data->c_tex = conv_int(data, temp);
		free(temp); 
	}
	else if (is_blank_line(data->file[i]))
		return ;
	else
		exit_error(data, "Invalid format in file", i + 1);
}

void	parse_line_value(t_data *data, char **var, int i, char *cmp)
{
	int	j;

	(void)data; // Comment free en cas d'erreur? lst alloc?
	j = 0;
	if (*var != NULL)
		exit_error(data, "Invalid value line: Value set-up twice", i + 1);
	while (data->file[i][j] == ' ')
		j++;
	if (ft_strncmp(&data->file[i][j], cmp, ft_strlen(cmp)))
		exit_error(data, "Invalid value line: ID should be first in line", i + 1);
	j += ft_strlen(cmp);
	if (data->file[i][j] != ' ')
		exit_error(data, "Invalid value line: ID and value must be separated", i + 1);
	while (data->file[i][j] == ' ')
		j++;
	if (data->file[i][j] == '\0')
		exit_error(data, "Invalid value line: No value found on line", i + 1);
	*var = ft_strdup_l(&data->file[i][j], ' ');
	if (var == NULL)
		exit_error(data, "Memory allocation issue", -1);
	j += ft_strlen(*var);
	while (data->file[i][j] == ' ')
		j++;
	if (data->file[i][j] != '\0')
		exit_error(data, "Invalid value line: Multiple value on line", i + 1);
}
