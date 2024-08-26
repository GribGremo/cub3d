/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hexcolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:32:58 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/26 16:39:57 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char     *rgb_to_hex(t_data *data, char *rgb)
{
    (void)data;
    int i;
    int loop;
    char *col;
    char *start;

    col = NULL;
    start = NULL;
    loop = 0;
    i = 0;
    start = malloc(sizeof(char) * (1 + 1));
    if (start == NULL)
        exit_error("Memory allocation issue", -1);
    start[0] = '#';
    start[1] = '\0';
    while(rgb[i] != '\0')
    {
        if(loop < 2)
            col = get_value_rgb(rgb, ',', &i);
        else if (loop == 2)
            col = get_value_rgb(rgb, '\0', &i);
        start = ft_strjoin_f(start, col);
        if (start == NULL)
            exit_error("Memory allocation issue", -1);
        loop++;
    }
    return (start);
}

char *get_col_string(char *rgb, char lmt, int *i)
{
    char *col;
    int j;

    j = 0;
    col = NULL;
    while(ft_isdigit(rgb[(*i)]))
    {
        (*i)++;
        j++;
    }
    if (rgb[*i] != lmt)
        exit_error("Invalid value line: Invalid RGB format", -1);
    col = malloc(sizeof(char) * (j + 1));
    if (col == NULL)
        exit_error("Memory allocation issue", -1);
    *i = *i - j;
    j = 0;
    while(ft_isdigit(rgb[*i]))
        col[j++] = rgb[(*i)++];
    col[j] = '\0';
    if(rgb[*i] != '\0')
        (*i)++;
    return (col);
}

char    *get_value_rgb(char *rgb, char lmt, int *i)
{
    int f;
    char *col;
    int res;

    res = 0;
    f = 0;
    col = get_col_string(rgb, lmt, i);
    res = ft_atoll(col, &f);
    free(col);
    if (res < 0 || f == 1 || res > 255)
        exit_error("Invalid value line: Invalid RGB value", -1);
    col = ft_itoa_hex(res);
    if (col == NULL)
        exit_error("Memory allocation issue", -1);
    return (col);
}
