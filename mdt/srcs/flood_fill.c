/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:37:38 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/31 15:06:41 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_copy(char **copy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (copy[i] != NULL)
	{
		while (copy[i][j] != '\0')
		{
			if (copy[i][j] == '0')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

char	**copy_tab(t_data *data, char **tab)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc((ft_tablen(tab) + 2) * sizeof(char *));
	if (new == NULL)
		exit_error(data, "Memory allocation issue", -1);
	while (tab[i] != NULL)
	{
		new[i] = ft_strdup(tab[i]);
		if (new[i] == NULL)
		{
			free_tab(new);
			exit_error(data, "Memory allocation issue", -1);
		}
		i++;
	}
	new[i] = NULL;
	return (new);
}

int	fullfill(char **copy, int y, int x)
{
	if (copy[y][x] == '2')
	{
		return (1);
	}
	if (copy[y][x] != '1' && copy[y][x] != 'X')
	{
		copy[y][x] = 'X';
		fullfill(copy, y - 1, x);
		fullfill(copy, y + 1, x);
		fullfill(copy, y, x - 1);
		fullfill(copy, y, x + 1);
	}
	return (0);
}
