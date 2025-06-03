/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:10:33 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/03 15:20:36 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_array(char **array)
{
	int i;

	i = 0;
	if (!array)
		return ;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void free_textures(t_data *data)
{
    if (!data->texture)
        return;
    if (data->texture->north_texture)
        mlx_delete_texture(data->texture->north_texture);
    if (data->texture->south_texture)
        mlx_delete_texture(data->texture->south_texture);
    if (data->texture->west_texture)
        mlx_delete_texture(data->texture->west_texture);
    if (data->texture->east_texture)
        mlx_delete_texture(data->texture->east_texture);
    free(data->texture);
    data->texture = NULL;
}

void free_data(t_data *data)
{
	if (!data)
		return ;
    if (data->map)
    {
        if (data->map->file_content)
            free_array(data->map->file_content);
		if (data->map->map)
            free_array(data->map->map);
        free(data->map);
		data->map = NULL;
    }
	if (data->texture)
		free_textures(data);
	if (data->counter)
	{
		free(data->counter);
		data->counter = NULL;
	}
}
