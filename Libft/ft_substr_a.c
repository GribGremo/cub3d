/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:06:20 by sylabbe           #+#    #+#             */
/*   Updated: 2024/06/10 10:45:55 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_a(t_alloc **lst_alloc, char const *s,
	unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	if ((int)start > ft_strlen(s))
		len = 0;
	str = ft_calloc(len + 2, sizeof(char));
	if (add_alloc(lst_alloc, str, NULL))
		return (0);
	while ((int)start < (int)len && s[start] != '\0')
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
