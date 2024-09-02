/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:18:29 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/02 17:07:13 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../../Libft/libft.h"
# include "stdio.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_player
{
	int			px;
	int			py;
}				t_player;

typedef struct s_map
{
	int			map_x;
	int			map_y;
	int			map_s;
	char		**map;
}				t_map;

typedef struct s_data
{
	char		*n_tex;
	char		*s_tex;
	char		*e_tex;
	char		*w_tex;
	int			f_tex;
	int			c_tex;
	char		**file;
	t_player	*player;
	t_map		*map;
}				t_data;

// DEBUG(A EFFACER)
void			print_array(char **array);
void			print_textures(t_data *data);

// MAIN
void			check_args(t_data *data, int argc, char **argv);
void			exit_error(t_data *data, char *msg, int line);
void			init_data(t_data *data);

// CREATE MAP
char			*create_map_line(t_data *data, char *line);
void			empty_line_in_map(t_data *data, int i);
void			set_up_map_var(t_data *data, int i);
void			create_map(t_data *data, int i);

// PARSE MAP
int				check_player(t_data *data, int i, int j, char **map);
void			check_close_map(t_data *data, char **map);

// PARSE FILE
void			filedup(t_data *data, char **argv);
void			parse_file(t_data *data);
void			get_file_value(t_data *data, int i);
void			parse_line_value(t_data *data, char **var, int i, char *cmp);

// RGB TO HEXCOLOR
char			*get_col_string(t_data *data, char *rgb, char lmt, int *i);
int				get_value_rgb(t_data *data, char *rgb, char lmt, int *i);
int				conv_int(t_data *data, char *rgb);

// FREE ALL
void			ft_free_all(t_data *data);
void			ft_free(void **var);
void			ft_free_array(void ***array);

// UTILS PARSING
int				is_file_readable(char *filename);
char			*ft_strdup_l(char *str, char limit);
int				is_blank_line(char *line);
int				is_map_line(char *line);
void			skip_spaces(char *str, int *i);
int				ft_tablen_c(char **str);

#endif