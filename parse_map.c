/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:44:36 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/28 12:23:05 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.c"

int parse_map(t_data *data)
{
    int i;

    i = 0;

    
}
void check_close_map(t_data *data, char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i] != NULL)
    {
        if (map[i][0] == '\0')
            exit_error("Empty line in map", - 1);
        while(map[i][j] != '\0')
        {
            if (map[i][j] == '0')

            j++;
        }
        j = 0;
        i++;
    }

}
