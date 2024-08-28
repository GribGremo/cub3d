/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:04:28 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/28 15:50:28 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_file_readable(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY); // A verifier pour les dossiers
	if (fd == -1)
		return (0);
	else
	{
		close(fd);
		return (1);
	}
}

char	*ft_strdup_l(char *str, char limit)
{
	int		i;
	int		size;
	char	*res;

	size = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != limit)
	{
		size++;
		i++;
	}
	res = malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != limit)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	is_blank_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_line(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}