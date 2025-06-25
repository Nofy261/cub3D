/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:02:00 by rraumain          #+#    #+#             */
/*   Updated: 2025/06/26 00:52:22 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_movement(t_data *data, double delta_time)
{
	if (data->key_up)
		handle_collision(data, 0, delta_time);
	if (data->key_down)
		handle_collision(data, M_PI, delta_time);
	if (data->key_left)
		handle_collision(data, -M_PI / 2, delta_time);
	if (data->key_right)
		handle_collision(data, M_PI / 2, delta_time);
	if (data->key_rotate_left)
		rotate_camera(data, -SPEED * delta_time);
	if (data->key_rotate_right)
		rotate_camera(data, SPEED * delta_time);
}

int	render_frame(void *param)
{
	t_data	*data;
	double	now;
	double	delta_time;
	char	*fps;

	data = param;
	now = get_time();
	delta_time = now - data->last_time;
	data->last_time = now;
	handle_movement(data, delta_time);
	raycast_loop(data);
	mlx_put_image_to_window(data->mlx, data->window, data->screen.image, 0, 0);
	fps = ft_itoa((int)(1 / delta_time + 0.5));
	if (fps)
	{
		mlx_string_put(data->mlx, data->window, 20, 20, 0xFF0000, fps);
		free(fps);
	}
	return (0);
}
