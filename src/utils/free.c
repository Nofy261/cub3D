/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:10:33 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 15:12:03 by rraumain         ###   ########.fr       */
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
	if (!data || !data->mlx_ptr)
		return;
	if (data->north_texture.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->north_texture.img_ptr);
	if (data->south_texture.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->south_texture.img_ptr);
	if (data->west_texture.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->west_texture.img_ptr);
	if (data->east_texture.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->east_texture.img_ptr);
	if (data->screen.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->screen.img_ptr);
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