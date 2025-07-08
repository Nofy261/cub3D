/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:19:48 by rraumain          #+#    #+#             */
/*   Updated: 2025/07/08 10:38:28 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	handle_collision(t_data *data, double orientation, double delta_time)
// {
// 	double	angle;
// 	double	new_x;
// 	double	new_y;

// 	angle = atan2(data->player.dir_y, data->player.dir_x);
// 	new_x = data->player.pos_x + cos(angle + orientation) * SPEED * delta_time;
// 	new_y = data->player.pos_y + sin(angle + orientation) * SPEED * delta_time;
// 	if (data->map.map[(int)new_y][(int)new_x] != '1')
// 	{
// 		data->player.pos_x = new_x;
// 		data->player.pos_y = new_y;
// 	}
// 	return (0);
// }


int	handle_collision(t_data *data, double orientation, double delta_time) //modif
{
	double	angle;
	double	new_x;
	double	new_y;

	angle = atan2(data->player.dir_y, data->player.dir_x);
	new_x = data->player.pos_x + cos(angle + orientation) * SPEED * delta_time;
	new_y = data->player.pos_y + sin(angle + orientation) * SPEED * delta_time;

	// Séparer les collisions en X et Y pour plus de souplesse
	if (data->map.map[(int)data->player.pos_y][(int)new_x] != '1')
		data->player.pos_x = new_x;
	if (data->map.map[(int)new_y][(int)data->player.pos_x] != '1')
		data->player.pos_y = new_y;
	return (0);
}

void	rotate_camera(t_data *data, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(angle)
		- data->player.dir_y * sin(angle);
	data->player.dir_y = old_dir_x * sin(angle)
		+ data->player.dir_y * cos(angle);
	data->player.plane_x = data->player.plane_x * cos(angle)
		- data->player.plane_y * sin(angle);
	data->player.plane_y = old_plane_x * sin(angle)
		+ data->player.plane_y * cos(angle);
}
