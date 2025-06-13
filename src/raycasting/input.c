/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:19:22 by rraumain          #+#    #+#             */
/*   Updated: 2025/06/13 10:37:28 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	on_key_press(int keycode, t_data *data)
{
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		data->key_up = 1;
	else if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		data->key_down = 1;
	else if (keycode == XK_a || keycode == XK_A || keycode == XK_Left)
		data->key_left = 1;
	else if (keycode == XK_d || keycode == XK_D || keycode == XK_Right)
		data->key_right = 1;
	else if (keycode == XK_Escape)
		mlx_destroy_window(data->mlx, data->window);
}

static void	on_key_release(int keycode, t_data *data)
{
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		data->key_up = 0;
	else if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		data->key_down = 0;
	else if (keycode == XK_a || keycode == XK_A || keycode == XK_Left)
		data->key_left = 0;
	else if (keycode == XK_d || keycode == XK_D || keycode == XK_Right)
		data->key_right = 0;
}

static int	key_press_event(int keycode, t_data *data)
{
	on_key_press(keycode, data);
	return (0);
}

static int	key_release_event(int keycode, t_data *data)
{
	on_key_release(keycode, data);
	return (0);
}

void	handle_input_hooks(t_data *data)
{
	mlx_hook(data->window, KeyPress,   KeyPressMask, key_press_event, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, key_release_event, data);
}

