/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:09:58 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/25 12:16:51 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_array(char **array)
{
    int i;

    i = 0;
    if (!array)
        return ;
    while(array[i] != NULL)
    {
        printf("%s\n", array[i]);
        i++;
    }
}

void    print_textures(t_data *data)
{
    printf("FILE VALUES:\n\n");
    printf("NORTH_TEXTURE: %s\n", data->n_tex);
    printf("SOUTH_TEXTURE: %s\n", data->s_tex);
    printf("EAST_TEXTURE: %s\n", data->e_tex);
    printf("WEST_TEXTURE: %s\n", data->w_tex);
    printf("FLOOR_RGB: %s\n", data->f_tex);
    printf("CEILING_RGB: %s\n\n", data->c_tex);
}
