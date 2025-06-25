/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:19:22 by rraumain          #+#    #+#             */
/*   Updated: 2025/06/26 00:38:55 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	on_key_press(int keycode, t_data *data)
{
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		data->key_up = 1;
	else if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		data->key_down = 1;
	else if (keycode == XK_a || keycode == XK_A)
		data->key_left = 1;
	else if (keycode == XK_d || keycode == XK_D)
		data->key_right = 1;
	else if (keycode == XK_Left)
		data->key_rotate_left = 1;
	else if (keycode == XK_Right)
		data->key_rotate_right = 1;
	else if (keycode == XK_Escape)
	{
		free_data(data);
		exit(0);
	}
	return (0);
}

static int	on_key_release(int keycode, t_data *data)
{
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		data->key_up = 0;
	else if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		data->key_down = 0;
	else if (keycode == XK_a || keycode == XK_A)
		data->key_left = 0;
	else if (keycode == XK_d || keycode == XK_D)
		data->key_right = 0;
	else if (keycode == XK_Left)
		data->key_rotate_left = 0;
	else if (keycode == XK_Right)
		data->key_rotate_right = 0;
	return (0);
}

static int	close_window(t_data *data)
{
	free_data(data);
	exit(0);
}

void	handle_input_hooks(t_data *data)
{
	mlx_hook(data->window, KeyPress, KeyPressMask, on_key_press, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, on_key_release, data);
	mlx_hook(data->window, 17, 0, close_window, data);
}
