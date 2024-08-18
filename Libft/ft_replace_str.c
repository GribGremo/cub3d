/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:59:51 by sylabbe           #+#    #+#             */
/*   Updated: 2024/07/10 17:18:02 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//If origin is found in str,return the index of start 
// of origin in str, else return -1
int	get_index_to_replace(char *str, char *origin, int i)
{
	while (str[i] != '\0')
	{
		if (!ft_strncmp(&str[i], origin, ft_strlen(origin)))
			return (i);
		i++;
	}
	return (-1);
}

//Replace a string(origin) by another string(new)
// in a string(str) and return the result, if no origin 
// found return a duplicate str 
char	*ft_replace_str(char *str, char *origin, char *new, int lmt)
{
	char	*before;
	char	*after;
	char	*res;
	int		start;

	if (str == NULL || origin == NULL || new == NULL)
		return (NULL);
	start = get_index_to_replace(str, origin, lmt);
	if (start == -1)
		return (ft_strdup(str));
	before = ft_substr(str, 0, start);
	if (before == NULL)
		return (NULL);
	after = ft_substr(str, start + ft_strlen(origin), ft_strlen(str));
	if (after == NULL)
		return (NULL);
	res = ft_strjoin(before, new);
	if (res == NULL)
		return (NULL);
	res = ft_strjoin_f(res, after);
	if (res == NULL)
		return (NULL);
	free(before);
	return (res);
}
