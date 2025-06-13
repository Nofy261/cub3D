/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:14:38 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/13 10:29:36 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_angle_from_facing(t_data *data, char facing)
{
	if (facing == 'N')
	{
		data->player.dir_x   =  0.0;
		data->player.dir_y   = -1.0;
		data->player.plane_x =  0.66;
		data->player.plane_y =  0.0;
	}
	else if (facing == 'S')
	{
		data->player.dir_x   =  0.0;
		data->player.dir_y   =  1.0;
		data->player.plane_x = -0.66;
		data->player.plane_y =  0.0;
	}
	else if (facing == 'E')
	{
		data->player.dir_x   =  1.0;
		data->player.dir_y   =  0.0;
		data->player.plane_x =  0.0;
		data->player.plane_y =  0.66;
	}
	else if (facing == 'W')
	{
		data->player.dir_x   = -1.0;
		data->player.dir_y   =  0.0;
		data->player.plane_x =  0.0;
		data->player.plane_y = -0.66;
	}
}
