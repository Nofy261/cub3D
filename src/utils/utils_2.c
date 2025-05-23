/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:20:42 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/23 11:55:02 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_data(t_data *data)
{
    if (data->map)
    {
        if (data->map->file_content)
            free_array(data->map->file_content);
        free(data->map);
    }
    if (data->texture)
        free(data->texture);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}



