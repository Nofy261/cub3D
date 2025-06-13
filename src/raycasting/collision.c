/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:19:48 by rraumain          #+#    #+#             */
/*   Updated: 2025/06/13 14:36:18 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_collision(t_data *data, double orientation)
{
	double angle;
	double new_x;
	double new_y;

	angle = atan2(data->player.dir_y, data->player.dir_x);
	new_x = data->player.pos_x + cos(angle + orientation) * 0.05;
	new_y = data->player.pos_y + sin(angle + orientation) * 0.05;
	if (data->map.map[(int)new_y][(int)new_x] != '1')
	{
		data->player.pos_x = new_x;
		data->player.pos_y = new_y;
	}
	return (0);
}
