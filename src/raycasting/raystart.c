/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raystart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:53:27 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/12 10:10:17 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit_error(data, "MLX init failed");
	data->window = mlx_new_window(data->mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT,
			"cub3d");
	if (data->window == NULL)
		exit_error(data, "Window creation failed");
	data->screen.image = mlx_new_image(data->mlx, WINDOWS_WIDTH,
			WINDOWS_HEIGHT);
	if (data->screen.image == NULL)
		exit_error(data, "Image creation failed");
	data->screen.data = mlx_get_data_addr(data->screen.image,
			&data->screen.bpp, &data->screen.size_line, &data->screen.endian);
	handle_input_hooks(data);
	mlx_loop_hook(data->mlx, render_frame, data);
	mlx_loop(data->mlx);
}
