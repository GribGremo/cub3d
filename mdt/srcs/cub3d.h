/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:18:29 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/29 16:29:40 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../../Libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "stdio.h"

typedef struct s_player
{
	int		px;
	int		py;
}   t_player;

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
    int f_tex;
    int c_tex;
    char **file;
    t_player *player;
    t_map *map;
}	t_data;

//cub3d.c
void check_args(t_data *data, int argc, char **argv);
void exit_error(t_data *data, char *msg, int line);
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
char *get_col_string(t_data *data, char *rgb, char lmt, int *i);
int get_value_rgb(t_data *data,char *rgb, char lmt, int *i);
int conv_int(t_data *data, char *rgb);


//
void	ft_free_all(t_data *data);
void	ft_free(void **var);
void	ft_free_array(void ***array);




void create_map(t_data *data, int i);

void    parse_line_value(t_data *data, char **var, int i, char *cmp);

//debug.c
void    print_array(char **array);
void    print_textures(t_data *data);

//
void check_close_map(t_data *data, char **map);
int	fullfill(char **copy, int y, int x);
char	**copy_tab(t_data *data, char **tab);
int	check_copy(char **copy);





#endif