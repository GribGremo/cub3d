/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:20:15 by sylabbe           #+#    #+#             */
/*   Updated: 2024/07/01 13:27:02 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *stro, const char *strt)
{
	int	i;

	i = 0;
	while (stro[i] != '\0' || strt[i] != '\0')
	{
		if (stro[i] != strt[i])
			return ((unsigned char)stro[i] - (unsigned char)strt[i]);
		i++;
	}
	if (stro[i] != strt[i])
		return ((unsigned char)stro[i] - (unsigned char)strt[i]);
	return (0);
}
