/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 08:06:55 by grib              #+#    #+#             */
/*   Updated: 2024/06/29 08:08:04 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allow us to to compare if a string(little) is FULLY
	included at the end of another string(big),
	if true return 1 else return 0*/
int	ft_strendstr(char *big, char *little)
{
	int	len_big;
	int	len_little;

	if (big == NULL || little == NULL)
		return (0);
	len_big = ft_strlen(big) - 1;
	len_little = ft_strlen(little) - 1;
	while (len_big >= 0 && len_little >= 0)
	{
		if (big[len_big] != little[len_little])
			return (0);
		len_big--;
		len_little--;
	}
	if (len_little == -1)
		return (1);
	else
		return (0);
}
