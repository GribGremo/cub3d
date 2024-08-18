/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:19:07 by sylabbe           #+#    #+#             */
/*   Updated: 2024/06/28 23:48:19 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Free all elements in an array and the array pointer
int	free_tab(char **array)
{
	int	i;

	if (array == NULL)
		return (0);
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}
