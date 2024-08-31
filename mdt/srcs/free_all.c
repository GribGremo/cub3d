/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:05:01 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/31 15:03:38 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Free all variables that use memory allocation
void	ft_free_all(t_data *data)
{
	ft_free((void **)&data->n_tex);
	ft_free((void **)&data->s_tex);
	ft_free((void **)&data->e_tex);
	ft_free((void **)&data->w_tex);
	ft_free((void **)&data->player);
	ft_free_array((void ***)&data->file);
	ft_free_array((void ***)&data->map->map);
	ft_free((void **)&data->map);
}

// free the adress pointed to, and pointer is set to NULL
void	ft_free(void **var)
{
	free(*var);
	*var = NULL;
}

/*free the whole strings in array and set them to NULL,
	free the array pointer and set it to NULL too*/
void	ft_free_array(void ***array)
{
	int	i;

	i = 0;
	if (array && *array != NULL)
	{
		while ((*array)[i] != NULL)
		{
			ft_free((void **)&(*array)[i]);
			i++;
		}
	}
	free(*array);
	*array = NULL;
}
