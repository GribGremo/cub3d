/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:20:06 by sylabbe           #+#    #+#             */
/*   Updated: 2024/09/02 15:33:57 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// a confirmer
char	*ft_strstr(char *str, char *cmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (cmp[j] && str[i + j] == cmp[j])
			j++;
		if (cmp[j] == '\0')
			return (&str[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
