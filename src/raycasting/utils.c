/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:14:38 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/26 00:57:42 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dir(t_data *data, double x, double y)
{
	data->player.dir_x = x;
	data->player.dir_y = y;
}

static void	set_plane(t_data *data, double x, double y)
{
	data->player.plane_x = x;
	data->player.plane_y = y;
}

void	set_player_angle_from_facing(t_data *data, char facing)
{
	if (facing == 'N')
	{
		set_dir(data, 0.0, -1.0);
		set_plane(data, 0.66, 0.0);
	}
	else if (facing == 'S')
	{
		set_dir(data, 0.0, 1.0);
		set_plane(data, -0.66, 0.0);
	}
	else if (facing == 'E')
	{
		set_dir(data, 1.0, 0.0);
		set_plane(data, 0.0, 0.66);
	}
	else if (facing == 'W')
	{
		set_dir(data, -1.0, 0.0);
		set_plane(data, 0.0, -0.66);
	}
}

double	get_time(void)
{
	struct timeval	tv;
	double			time;

	time = 0;
	gettimeofday(&tv, NULL);
	time = tv.tv_sec + tv.tv_usec * 1e-6;
	return (time);
}
