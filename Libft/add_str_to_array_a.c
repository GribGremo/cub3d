/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_to_array_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:23:32 by sylabbe           #+#    #+#             */
/*   Updated: 2024/05/24 12:07:42 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**add_str_to_array_a(t_alloc **lst_alloc, char **array, char *temp)
{
	int		i;
	char	**new;

	i = 0;
	if (array == NULL)
		new = malloc(2 * sizeof(char *));
	else
		new = malloc((ft_tablen(array) + 2) * sizeof(char *));
	if (add_alloc(lst_alloc, NULL, (void **)new))
		return (NULL);
	while (array != NULL && array[i] != NULL)
	{
		new[i] = array[i];
		i++;
	}
	new[i] = temp;
	new[i + 1] = NULL;
	free(array);
	return (new);
}
