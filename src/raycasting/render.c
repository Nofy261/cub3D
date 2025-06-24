/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:02:00 by rraumain          #+#    #+#             */
/*   Updated: 2025/06/24 11:29:29 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	rotate_camera(t_data *data, double angle)// test ajout 24-06
{
	double	old_dir_x = data->player.dir_x;
	double	old_plane_x = data->player.plane_x;

	data->player.dir_x = data->player.dir_x * cos(angle) - data->player.dir_y * sin(angle);
	data->player.dir_y = old_dir_x * sin(angle) + data->player.dir_y * cos(angle);

	data->player.plane_x = data->player.plane_x * cos(angle) - data->player.plane_y * sin(angle);
	data->player.plane_y = old_plane_x * sin(angle) + data->player.plane_y * cos(angle);
}


int	render_frame(void *param)
{
	t_data *data = param;

	if (data->key_up)
		handle_collision(data, 0);
	if (data->key_down)
		handle_collision(data, M_PI);
	if (data->key_left)
		handle_collision(data, -M_PI / 2);
	if (data->key_right)
		handle_collision(data, M_PI / 2);
	if (data->key_rotate_left) // ajout 24-06
		rotate_camera(data, -ROT_SPEED);
	if (data->key_rotate_right) // ajout 24-06
		rotate_camera(data, ROT_SPEED);
	raycast_loop(data);
	mlx_put_image_to_window(data->mlx, data->window, data->screen.image, 0, 0);
	return (0);
}
