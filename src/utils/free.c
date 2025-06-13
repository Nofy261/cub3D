/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:10:33 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/12 10:05:19 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_array(char **array)
{
	int i = 0;

	if (!array)
		return;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void free_textures(t_data *data)
{
	if (!data || !data->mlx)
		return;
	if (data->north_texture.image)
		mlx_destroy_image(data->mlx, data->north_texture.image);
	if (data->south_texture.image)
		mlx_destroy_image(data->mlx, data->south_texture.image);
	if (data->west_texture.image)
		mlx_destroy_image(data->mlx, data->west_texture.image);
	if (data->east_texture.image)
		mlx_destroy_image(data->mlx, data->east_texture.image);
	if (data->screen.image)
		mlx_destroy_image(data->mlx, data->screen.image);
}

void free_data(t_data *data)
{
	if (!data)
		return;
	free_textures(data);
	if (data->map.file_content)
		free_array(data->map.file_content);
	if (data->map.map)
		free_array(data->map.map);
}
