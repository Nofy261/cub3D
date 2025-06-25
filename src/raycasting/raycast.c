/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:13:48 by rraumain          #+#    #+#             */
/*   Updated: 2025/06/26 00:49:22 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_border_x(t_data *data, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (data->player.pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1 - data->player.pos_x) * ray->delta_x;
	}
}

static void	find_border_y(t_data *data, t_ray *ray)
{
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (data->player.pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1 - data->player.pos_y) * ray->delta_y;
	}
}

static void	init_raycast(t_data *data, int x, t_ray *ray)
{
	double	cam;

	cam = 2 * x / (double)WINDOWS_WIDTH - 1;
	ray->dir_x = data->player.dir_x + data->player.plane_x * cam;
	ray->dir_y = data->player.dir_y + data->player.plane_y * cam;
	ray->map_x = (int)data->player.pos_x;
	ray->map_y = (int)data->player.pos_y;
	ray->delta_x = fabs(1.0 / ray->dir_x);
	ray->delta_y = fabs(1.0 / ray->dir_y);
	find_border_x(data, ray);
	find_border_y(data, ray);
}

static void	perform_dda(t_data *data, t_ray *ray)
{
	while (1)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map.map[ray->map_y][ray->map_x] == '1')
			break ;
	}
}

void	raycast_loop(t_data *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WINDOWS_WIDTH)
	{
		init_raycast(data, x, &ray);
		perform_dda(data, &ray);
		if (ray.side == 0)
			ray.perp_dist = ray.side_x - ray.delta_x;
		else
			ray.perp_dist = ray.side_y - ray.delta_y;
		draw_background(data, x);
		draw_wall(data, x, &ray);
		x++;
	}
}
