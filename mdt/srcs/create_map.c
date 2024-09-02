/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 03:04:50 by grib              #+#    #+#             */
/*   Updated: 2024/09/02 15:29:50 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Create map line if char = ' ' or,
	if length inferior at the max line lenght replace char by '2' */
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

/*Check if there is invalid character in map, and if an empty line,
	containing only '\0' is in the middle of the map lines*/
void	empty_line_in_map(t_data *data, int i)
{
	while (data->file[i] != NULL && data->file[i][0] != '\0')
	{
		if (!is_map_line(data->file[i]))
			exit_error(data, "Invalid character in map", -1);
		i++;
	}
	while (data->file[i] != NULL && data->file[i][0] == '\0')
		i++;
	if (data->file[i] != NULL && is_map_line(data->file[i]))
		exit_error(data, "Empty line in map", -1);
	else if (data->file[i] != NULL && !is_map_line(data->file[i]))
		exit_error(data, "Invalid line after map", -1);
}

/* Set up variable of structure map(max line lenght,
	number of line containg map, and map array)*/
void	set_up_map_var(t_data *data, int i)
{
	int	j;

	j = i;
	while (data->file[j] != NULL)
	{
		if (data->map->map_x < ft_strlen(data->file[j]) + 2)
			data->map->map_x = ft_strlen(data->file[j]) + 2;
		j++;
	}
	data->map->map_y = ft_tablen_c(&data->file[i]) + 2;
	data->map->map = malloc(sizeof(char *) * (data->map->map_y + 1));
	if (data->map->map == NULL)
		exit_error(data, "Memory allocation issue", -1);
}

/*Create the map to have a rectangular map, filled with '2'*/
void	create_map(t_data *data, int i)
{
	int	j;

	j = 1;
	empty_line_in_map(data, i);
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
