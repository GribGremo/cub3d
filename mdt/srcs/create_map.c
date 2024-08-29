/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 03:04:50 by grib              #+#    #+#             */
/*   Updated: 2024/08/29 03:05:54 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.c"

char *create_map_line(t_data *data, char *line)
{
	int i;
	char *str;

	i = 0;
	str = NULL;
	str = malloc(sizeof(char) * data->map->map_x + 1);
	if (str == NULL)
		exit_error("Memory allocation issue", - 1);
	str[0] = '2';
	while(line[i] != '\0')
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

void set_up_map_var(t_data *data, int i)
{
	int j;

	j = i;
	while(data->file[j] != NULL)
	{
		if (!is_map_line(data->file[j]))
			exit_error("Invalid character in map", -1);//Attention '\0' ou pas
		if (data->map->map_x < ft_strlen(data->file[j]) + 2)
			data->map->map_x = ft_strlen(data->file[j]) + 2;
		j++;
	}
	data->map->map_y = ft_tablen(&data->file[i]) + 2; //
	data->map->map = malloc(sizeof(char *) * (data->map->map_y + 1)); //
	if (data->map->map == NULL) //
		exit_error("Memory allocation issue", -1);
	// printf("x:%d\ny :%d\n", data->map->map_x, data->map->map_y);
}

void	create_map(t_data *data, int i)
{
	int	j;

	j = 1;
	set_up_map_var(data, i);
	data->map->map[0] = create_map_line(data, "\0");
	while (data->file[i] != NULL)
	{
		// data->map->map[j] = ft_strdup(data->file[i]);
		data->map->map[j] = create_map_line(data, data->file[i]);
		if (data->map->map[j] == NULL)
			exit_error("Memory allocation issue", -1);
		i++;
		j++;
	}
	data->map->map[data->map->map_y - 1] = create_map_line(data, "\0");
	data->map->map[data->map->map_y] = NULL;
}