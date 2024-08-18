/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:18:29 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/18 19:54:41 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../../Libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "stdio.h"

typedef struct s_data
{
    char *north_texture;
    char *south_texture;
    char *east_texture;
    char *west_texture;
    char *floor_texture;
    char *ceiling_texture;
    char **map;
}	t_data;

//cub3d.c
void check_args(int argc, char **argv);
void exit_error(char *msg);
int is_file_readable(char *filename);
void parse_mapfile(t_data *data, char **argv);
void    print_array(char **array);
void init_data(t_data *data);





#endif