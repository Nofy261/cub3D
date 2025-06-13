/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:02:00 by rraumain          #+#    #+#             */
/*   Updated: 2025/06/13 15:07:12 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	raycast_loop(data);
	mlx_put_image_to_window(data->mlx, data->window, data->screen.image, 0, 0);
	return (0);
}
