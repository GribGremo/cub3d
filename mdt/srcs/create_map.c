/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 03:04:50 by grib              #+#    #+#             */
/*   Updated: 2024/08/31 15:54:48 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*create_map_line(t_data *data, char *line)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	str = malloc(sizeof(char) * data->map->map_x + 1);
	if (str == NULL)
		exit_error(data, "Memory allocation issue", -1);
	str[0] = '2';
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			str[i + 1] = '2';
		else
			str[i + 1] = line[i];
		i++;
	}
	while (i + 1 < data->map->map_x)
	{
		str[i + 1] = '2';
		i++;
	}
	str[i + 1] = '\0';
	return (str);
}

void	set_up_map_var(t_data *data, int i)
{
	int	j;

	j = i;
	while (data->file[j] != NULL)
	{
		if (!is_map_line(data->file[j]))
			exit_error(data, "Invalid character in map", -1);
		if (data->file[j][0] == '\0')
			exit_error(data, "Empty line in map", -1);
				// Attention '\0' ou pas
		if (data->map->map_x < ft_strlen(data->file[j]) + 2)
			data->map->map_x = ft_strlen(data->file[j]) + 2;
		j++;
	}
	data->map->map_y = ft_tablen_c(&data->file[i]) + 2;                 //
	data->map->map = malloc(sizeof(char *) * (data->map->map_y + 1)); //
	if (data->map->map == NULL)                                       //
		exit_error(data, "Memory allocation issue", -1);
}

void	create_map(t_data *data, int i)
{
	int	j;

	j = 1;
	set_up_map_var(data, i);
	data->map->map[0] = create_map_line(data, "\0");
	while (data->file[i] != NULL && data->file[i][0] != '\0')
	{
		data->map->map[j] = create_map_line(data, data->file[i]);
		if (data->map->map[j] == NULL)
			exit_error(data, "Memory allocation issue", -1);
		i++;
		j++;
	}
	data->map->map[data->map->map_y - 1] = create_map_line(data, "\0");
	data->map->map[data->map->map_y] = NULL;
}
int	empty_line_in_map(t_data *data, int i)
{
	int f;

	f = 0;
	while (data->file[j] != NULL && is_map_line(data->file[j]))
	{
		if (is_map_line(data->file[j]) && f == 1)
			exit_error(data, "Empty line in map", -1);
		if (!is_map_line(data->file[j]))
			exit_error(data, "Invalid character in map", -1);
		if (data->file[j][0] == '\0')
			f = 1;
				// Attention '\0' ou pas
		if (data->map->map_x < ft_strlen(data->file[j]) + 2)
			data->map->map_x = ft_strlen(data->file[j]) + 2;
		j++;
	}
	if (data->file[j] != NULL)
		exit_error(data, "Invalid map line", -1);
}