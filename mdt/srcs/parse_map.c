/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:44:36 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/02 15:26:16 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Check if cell is representing a player,
	and if this player is on a valid part of map,
	return 1 else return 0*/
int	check_player(t_data *data, int i, int j, char **map)
{
	if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
			|| map[i][j] == 'W') && (map[i + 1][j] != '2' && map[i
			- 1][j] != '2' && map[i][j + 1] != '2' && map[i][j - 1] != '2'))
	{
		data->player->px = j;
		data->player->py = i;
		return (1);
	}
	else if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
			|| map[i][j] == 'W') && (map[i + 1][j] == '2' || map[i
			- 1][j] == '2' || map[i][j + 1] == '2' || map[i][j - 1] == '2'))
		exit_error(data, "Player is on invalid map part", -1);
	else
		return (0);
	return (0);
}

/*check if each cell of array with '0' as value,
	is not next to a cell representing void '2',
	also check the number of player in map*/
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
			}
			player += check_player(data, i, j, map);
			j++;
		}
		j = 0;
		i++;
	}
	if (player != 1)
		exit_error(data, "Invalid number of player in map", -1);
}
