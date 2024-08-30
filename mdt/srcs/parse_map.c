/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:44:36 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/30 15:37:12 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int parse_map(t_data *data)
// {
//     int i;

//     i = 0;

// }

// void 	check_player(t_data)
// {
	
// }
void	check_close_map(t_data *data, char **map)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0')
			{
				if (map[i + 1][j] == '2' || map[i - 1][j] == '2' || map[i][j
					+ 1] == '2' || map[i][j - 1] == '2')
					exit_error(data, "Map unclosed", -1);
				// if (fullfill(cpy, i, j))
				// {
				//     free_tab(cpy);
				//     exit_error(data, "Map unclosed", -1);
				// }
				// print_array(cpy);
				// printf("\n");
			}
			if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
					|| map[i][j] == 'W') && (map[i + 1][j] != '2' & map[i
					- 1][j] != '2' && map[i][j + 1] != '2' && map[i][j
					- 1] != '2'))
			{
				data->player->px = j;
				data->player->py = i;
				player++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (player != 1)
		exit_error(data, "Invalid number of player in map", -1);
}
