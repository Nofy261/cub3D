/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:17:38 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/21 15:22:36 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void allocate(t_data *data)
{
    data->map = malloc(sizeof(t_map));
    if (!data->map)
    {
        //free();??
        exit(EXIT_FAILURE);
    }
    data->texture = malloc(sizeof(t_texture));
    if (!data->texture)
    {
        //free();
        free(data->map);
        exit(EXIT_FAILURE);
    }
    
}


void init(t_data *data)
{
    data->texture->north_texture = NULL;
    data->texture->south_texture = NULL;
    data->texture->west_texture = NULL;
    data->texture->east_texture = NULL;
    data->map->file_content = NULL;
   
}
