/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:40:11 by sylabbe           #+#    #+#             */
/*   Updated: 2023/12/03 14:41:16 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	int				i;

	i = 0;
	if (!s || (int)start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if ((int)len > ft_strlen(s))
		len = ft_strlen(s);
	if (len > (ft_strlen(s) - start))
		str = (char *)malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < (int)len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
