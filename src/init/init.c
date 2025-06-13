/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:17:38 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/13 10:46:39 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	reset_color(int *c)
{
	c[0] = -1;
	c[1] = -1;
	c[2] = -1;
}

void	init(t_data *data)
{
	ft_memset(data, 0, sizeof(*data));
	reset_color(data->map.floor_color);
	reset_color(data->map.sky_color);
	data->player.pos_x = 1.0;
	data->player.pos_y = 1.0;
}
