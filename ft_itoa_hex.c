/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:21:30 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/25 18:04:45 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"


int get_size(int n);
char *fill_hex(int n, int i, char *res);


char *ft_itoa_hex(int n)
{
	char    *res;
	int		i;
	char	sgn;

	res = NULL;
	i = 0;
	sgn = 1;
    res = malloc(sizeof(char) * get_size(n) + 10);
    if (res == NULL)
        return (NULL);//
    res = fill_hex(n, 0, res);
	// res *= sgn;
    return (res);
}
int get_size(int n)
{
    int i;

    i = 0;
    while(n  >= 15)
    {
        n /= 15;
        i++;
    }
    if (n == 0)
        return (i);
    else
        return (i + 1);
}

char *fill_hex(int n, int i, char *res)
{
    // char *res;
    char *hex;

    hex = "0123456789ABCDEF";
    if (n >= 15)
    {
        res = fill_hex(n / 15, i + 1, res);
    }
    else
        res[i + 1] = '\0';
    res[i] = hex[n % 15];
    return (res);
}
#include <stdio.h>
int main()
{
    char *str;

    str = ft_itoa_hex(254);
    printf("%s\n", str);
}