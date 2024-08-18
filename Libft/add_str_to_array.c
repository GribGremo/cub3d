/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:22:04 by sylabbe           #+#    #+#             */
/*   Updated: 2024/05/24 12:08:38 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**add_str_to_array(char **array, char *temp)
{
	int		i;
	char	**new;

	i = 0;
	if (array == NULL)
		new = malloc(2 * sizeof(char *));
	else
		new = malloc((ft_tablen(array) + 2) * sizeof(char *));
	if (new == NULL)
	{
		ft_printf("Error : Memory allocation issue\n");
		return (NULL);
	}
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
