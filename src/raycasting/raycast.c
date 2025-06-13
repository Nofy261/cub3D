/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:13:48 by rraumain          #+#    #+#             */
/*   Updated: 2025/06/13 10:56:44 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_raycast(t_data *data, int x, t_ray *ray)
{
	double cam;

	cam = 2 * x / (double)WINDOWS_WIDTH - 1;
	ray->dir_x    = data->player.dir_x + data->player.plane_x * cam;
	ray->dir_y    = data->player.dir_y + data->player.plane_y * cam;
	ray->map_x    = (int)data->player.pos_x;
	ray->map_y    = (int)data->player.pos_y;
	ray->delta_x  = fabs(1.0 / ray->dir_x);
	ray->delta_y  = fabs(1.0 / ray->dir_y);
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

static void	perform_dda(t_data *data, t_ray *ray)
{
	while (1)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x  += ray->step_x;
			ray->side    = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y  += ray->step_y;
			ray->side    = 1;
		}
		if (data->map.map[ray->map_y][ray->map_x] == '1')
			break ;
	}
}

static void	draw_background(t_data *data, int x)
{
	unsigned int	sky;
	unsigned int	floor;
	int 			y;

	sky = RGB(data->map.sky_color[0], data->map.sky_color[1], data->map.sky_color[2]);
	floor = RGB(data->map.floor_color[0], data->map.floor_color[1], data->map.floor_color[2]);
	y = 0;
	while (y < WINDOWS_HEIGHT / 2)
	{
		*(unsigned int *)(data->screen.data + y * data->screen.size_line
		  + x * (data->screen.bpp / 8)) = sky;
		y++;
	}
	while (y < WINDOWS_HEIGHT)
	{
		*(unsigned int *)(data->screen.data + y * data->screen.size_line
		  + x * (data->screen.bpp / 8)) = floor;
		y++;
	}
}

static void	draw_wall(t_data *data, int x, t_ray *ray)
{
	int				height;
	int				start;
	int				end;
	unsigned int	color;
	int				y;

	height = (int)(WINDOWS_HEIGHT / ray->perp_dist);
	start = -height / 2 + WINDOWS_HEIGHT / 2;
	color = 0xFFFFFF;
	end = height / 2 + WINDOWS_HEIGHT / 2;
	if (start < 0)
		start = 0;
	if (end >= WINDOWS_HEIGHT)
		end = WINDOWS_HEIGHT - 1;
	if (ray->side == 1)
		color = (color >> 1) & 0x7F7F7F;
	y = start;
	while (y <= end)
	{
		*(unsigned int *)(data->screen.data + y * data->screen.size_line
			+ x * (data->screen.bpp / 8)) = color;
		y++;
	}
}

void	raycast_loop(t_data *data)
{
	int   x;
	t_ray ray;

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
