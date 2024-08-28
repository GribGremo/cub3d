/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:18:29 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/28 18:01:14 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../../Libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "stdio.h"


typedef struct s_map
{
	int		map_x;
	int		map_y;
    int     map_s;
    char     **map;
}   t_map;

typedef struct s_data
{
    char *n_tex;
    char *s_tex;
    char *e_tex;
    char *w_tex;
    char *f_tex;
    char *c_tex;
    t_map *map;
    char **file;
}	t_data;

//cub3d.c
void check_args(int argc, char **argv);
void exit_error(char *msg, int line);
int is_file_readable(char *filename);
void	filedup(t_data *data, char **argv);
void init_data(t_data *data);
void get_file_value(t_data *data, int i);
int is_blank_line(char *line);
int is_map_line(char *line);
char *ft_strdup_l(char *str, char limit);
void	parse_file(t_data *data);

//
char    *rgb_to_hex(t_data *data, char *rgb);
char *get_col_string(char *rgb, char lmt, int *i);
char    *get_value_rgb(char *rgb, char lmt, int *i);


//
void	ft_free_all(t_data *data);
void	ft_free(void **var);
void	ft_free_array(void ***array);




void create_map(t_data *data, int i);

void    parse_line_value(t_data *data, char **var, int i, char *cmp);

//debug.c
void    print_array(char **array);
void    print_textures(t_data *data);






#endif