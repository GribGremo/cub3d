/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:20:06 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/24 13:46:43 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>
char *ft_strstr(char *str, char *cmp)//a confirmer
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(str[i] != '\0')
    {
        while(cmp[j] && str[i + j] == cmp[j])
            j++;
        if (cmp[j] == '\0')
            return (&str[i]);
        j = 0;
        i++;
    }
    return (NULL);
}
// #include <stdio.h>
// int main()
// {
//     // ft_strstr("Ton tonton tond ton thon, Ton");
//     // ft_strstr("Ton tonton tond ton thon, Ton");
//     // ft_strstr("Ton tonton tond ton thon, Ton")
//     printf("%s", ft_strstr("Ton tonton tond ton thon", "thonate"));
// }