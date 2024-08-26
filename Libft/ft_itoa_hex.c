/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:21:30 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/26 15:44:05 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size = 1;
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

static void	fill_res(long int ln, char *res, int size)
{
	if (ln == 0)
		res[0] = '0';
	res[size] = '\0';
	if (ln < 0)
	{
		ln = ln * -1;
		res[0] = '-';
	}
	while (ln > 0)
	{
		if ((ln % 16) <= 9)
			res[size - 1] = (ln % 16) + 48;
		else if (ln % 16 > 9)
			res[size - 1] = (ln % 16) + 55;
		ln = ln / 16;
		size--;
	}
}

char	*ft_itoa_hex(int n)
{
	char		*res;
	int			size;
	long int	ln;

	ln = n;
	size = get_size(ln);
	res = malloc(size + 1 * sizeof(char));
	if (res == NULL)
		return (NULL);
	fill_res(ln, res, size);
	return (res);
}

// #include <stdio.h>
// int main()
// {
//     char *str;

//     str = ft_itoa_hex(254);
//     printf("%s\n", str);
// }