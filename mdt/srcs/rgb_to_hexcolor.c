/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hexcolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:32:58 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/31 15:04:13 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_col_string(t_data *data, char *rgb, char lmt, int *i)
{
	char	*col;
	int		j;

	j = 0;
	col = NULL;
	while (ft_isdigit(rgb[(*i)]))
	{
		(*i)++;
		j++;
	}
	if (rgb[*i] != lmt)
		exit_error(data, "Invalid value line: Invalid RGB format", -1);
	col = malloc(sizeof(char) * (j + 1));
	if (col == NULL)
		exit_error(data, "Memory allocation issue", -1);
	*i = *i - j;
	j = 0;
	while (ft_isdigit(rgb[*i]))
		col[j++] = rgb[(*i)++];
	col[j] = '\0';
	if (rgb[*i] != '\0')
		(*i)++;
	return (col);
}

int	get_value_rgb(t_data *data, char *rgb, char lmt, int *i)
{
	int		f;
	char	*col;
	int		res;

	res = 0;
	f = 0;
	col = get_col_string(data, rgb, lmt, i);
	res = ft_atoll(col, &f);
	free(col);
	if (res < 0 || f == 1 || res > 255)
		exit_error(data, "Invalid value line: Invalid RGB value", -1);
	return (res);
}

int	conv_int(t_data *data, char *rgb)
{
	int	loop;
	int	i;
	int	r;
	int	g;
	int	b;

	loop = 0;
	i = 0;
	r = 0;
	g = 0;
	b = 0;
	while (rgb[i] != '\0')
	{
		if (loop == 0)
			r = get_value_rgb(data, rgb, ',', &i);
		else if (loop == 1)
			g = get_value_rgb(data, rgb, ',', &i);
		else if (loop == 2)
			b = get_value_rgb(data, rgb, '\0', &i);
		loop++;
	}
	return (r << 16 | g << 8 | b);
}
// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }