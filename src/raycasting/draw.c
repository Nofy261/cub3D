/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:05:23 by rraumain          #+#    #+#             */
/*   Updated: 2025/06/26 11:36:15 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	select_texture(t_line_config *line_conf, t_data *data,
	t_ray *ray)
{
	t_texture	texture;

	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			texture = data->east_texture;
		else
			texture = data->west_texture;
	}
	else
	{
		if (ray->dir_y > 0)
			texture = data->south_texture;
		else
			texture = data->north_texture;
	}
	if (ray->side == 0)
		line_conf->wall_x = data->player.pos_y + ray->perp_dist * ray->dir_y;
	else
		line_conf->wall_x = data->player.pos_x + ray->perp_dist * ray->dir_x;
	line_conf->wall_x -= floor(line_conf->wall_x);
	line_conf->texture_x = (int)(line_conf->wall_x * (double)texture.width);
	return (texture);
}

static void	init_texture_pos(t_line_config *line_config, t_texture *texture,
	t_ray *ray)
{
	if (ray->side == 0 && ray->dir_x > 0)
		line_config->texture_x = texture->width - line_config->texture_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		line_config->texture_x = texture->width - line_config->texture_x - 1;
}

static void	draw_line(t_data *data, int x, t_line_config *line_config,
	t_texture *texture)
{
	unsigned int	color;

	line_config->texture_y = (int)line_config->texture_pos % texture->height;
	line_config->texture_pos += line_config->texture_step;
	color = *(unsigned int *)(texture->data
			+ line_config->texture_y * texture->size_line
			+ line_config->texture_x * (texture->bpp / 8));
	*(unsigned int *)(data->screen.data
			+ line_config->y * data->screen.size_line
			+ x * (data->screen.bpp / 8)) = color;
}

void	draw_background(t_data *data, int x)
{
	int				y;
	int32_t			sky;
	int32_t			floor;

	sky = rgb(data->map.sky_color[0], data->map.sky_color[1],
			data->map.sky_color[2]);
	floor = rgb(data->map.floor_color[0], data->map.floor_color[1],
			data->map.floor_color[2]);
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

void	draw_wall(t_data *data, int x, t_ray *ray)
{
	t_line_config	line_config;
	t_texture		texture;
	int				start;
	int				end;
	int				height;

	height = (int)(WINDOWS_HEIGHT / ray->perp_dist);
	start = -height / 2 + WINDOWS_HEIGHT / 2;
	end = height / 2 + WINDOWS_HEIGHT / 2;
	if (start < 0)
		start = 0;
	if (end >= WINDOWS_HEIGHT)
		end = WINDOWS_HEIGHT - 1;
	texture = select_texture(&line_config, data, ray);
	init_texture_pos(&line_config, &texture, ray);
	line_config.texture_step = (double)texture.height / (double)height;
	line_config.texture_pos = (start - WINDOWS_HEIGHT / 2 + height / 2)
		* line_config.texture_step;
	while (start <= end)
	{
		line_config.y = start;
		draw_line(data, x, &line_config, &texture);
		start++;
	}
}
