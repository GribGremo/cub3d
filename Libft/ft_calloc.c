/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:34:13 by sylabbe           #+#    #+#             */
/*   Updated: 2024/05/29 15:13:16 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementcount, size_t elementsize)
{
	char			*ptr;

	if (elementcount == 0 || elementsize == 0)
		return (malloc(0));
	if ((int)elementcount < 0 || (int)elementsize < 0)
		return (0);
	ptr = malloc(elementcount * elementsize);
	if (ptr == NULL)
		return (0);
	ft_bzero((unsigned char *)ptr, elementcount * elementsize);
	return (ptr);
}
