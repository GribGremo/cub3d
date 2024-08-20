/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:04:28 by sylabbe           #+#    #+#             */
/*   Updated: 2024/08/20 17:04:54 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_file_readable(char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY); // A verifier pour les dossiers
    if (fd == -1)
        return (0);
    else 
    {
        close(fd);
        return (1);
    }
}