/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:05:01 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/29 16:31:16 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_all(t_data *data)
{
	ft_free((void **)&data->n_tex);
	ft_free((void **)&data->s_tex);
	ft_free((void **)&data->e_tex);
	ft_free((void **)&data->w_tex);
	ft_free_array((void ***)&data->file);
	ft_free_array((void ***)&data->map->map);
	ft_free((void **)&data->map);	
}

void	ft_free(void **var)
{
	free(*var);
	*var = NULL;
}
void	ft_free_array(void ***array)
{
	int i;

	i = 0;
	if (array && *array != NULL)
	{
		while((*array)[i] != NULL)
		{
			ft_free((void **)&(*array)[i]); 
			i++;
		}
	}
	free(*array);
	*array = NULL;
}