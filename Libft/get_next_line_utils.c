/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:41:07 by sylabbe           #+#    #+#             */
/*   Updated: 2024/06/29 07:02:24 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_null(char *s1, char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (1);
	else if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL)
			free (s2);
		else if (s2 == NULL)
			free (s1);
		return (1);
	}
	return (0);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (check_null((char *)s1, (char *)s2))
		return (NULL);
	str = malloc((ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1) * sizeof(char));
	if (str == NULL)
	{
		free((char *)s1);
		free((char *)s2);
		return (NULL);
	}
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++j] != '\0')
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free ((char *)s2);
	free ((char *)s1);
	return (str);
}
