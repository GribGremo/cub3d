/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hexcolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:32:58 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/25 14:21:17 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    rgb_to_hex(t_data *data, char *rgb)
{
    char r_col[5];
    char g_col[5];
    char b_col[5];

    ft_strdup_l(rgb, ",");
}

int get_value_rgb(char *rgb)
{
    int i;
    char *col;
    int res;

    res = 0;
    i = 0;
    while(ft_isdigit(rgb[i]))
        i++;
    if (rgb[i] != ',')
        exit_error("Invalid value line: Invalid RGB format");
    col = malloc(sizeof(char) * (i + 1));
    if (col == NULL)
        exit_error("Memory allocation issue", -1);
    i = 0;
    while(ft_isdigit(rgb[i]))
    {
        col[i] = rgb[i];
        i++;
    }
    col[i] = '\0';
    i = 0;
    res = ft_atoll(col, i);
    free(col);
    if (res < 0 || i = 1 || res > 255);
        exit_error("Invalid value line: Invalid RGB value");
    col = 


}
