/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:17:38 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 15:14:32 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Plus besoin d'allouer map, counter, player, texture :
 * ce sont des champs embarqués dans t_data.
 */
void allocate(t_data *data)
{
	(void)data;
}

static void init_floor_ceiling(int *color)
{
	int i = 0;
	while (i < 3)
	{
		color[i++] = -1;
	}
}

void init(t_data *data)
{
	/* Pointeurs MLX */
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;

	/* Textures écran et murs */
	data->screen.img_ptr = NULL;
	data->screen.data    = NULL;
	data->north_texture.img_ptr = NULL;
	data->north_texture.data    = NULL;
	data->south_texture.img_ptr = NULL;
	data->south_texture.data    = NULL;
	data->west_texture.img_ptr  = NULL;
	data->west_texture.data     = NULL;
	data->east_texture.img_ptr  = NULL;
	data->east_texture.data     = NULL;

	/* Compteurs d'éléments */
	data->counter.count_no = 0;
	data->counter.count_so = 0;
	data->counter.count_we = 0;
	data->counter.count_ea = 0;
	data->counter.count_f  = 0;
	data->counter.count_c  = 0;

	/* Contenu du fichier et map */
	data->map.file_content   = NULL;
	data->map.map            = NULL;
	data->map.map_start_index = 0;
	data->map.width          = 0;
	data->map.height         = 0;
	init_floor_ceiling(data->map.floor_color);
	init_floor_ceiling(data->map.ceiling_color);

	/* Position et orientation du joueur (sera recalculée plus tard) */
	data->player.pos_x   = 1.0;
	data->player.pos_y   = 1.0;
	data->player.dir_x   = 0.0;
	data->player.dir_y   = 0.0;
	data->player.plane_x = 0.0;
	data->player.plane_y = 0.0;
}
