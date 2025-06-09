/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:17:38 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/09 12:44:53 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


 // free a completer
void allocate(t_data *data)
{
    data->map = malloc(sizeof(t_map));
    if (!data->map)
    {
        //free();??
        exit(EXIT_FAILURE);
    }
    data->texture = malloc(sizeof(t_texture));
    if (!data->texture)
    {
        free(data->map);
        exit(EXIT_FAILURE);
    }
    data->counter = malloc(sizeof(t_counter));
    if (!data->counter)
    {
        // free_data(data);
        free(data->texture);
        free(data->map);
        exit(EXIT_FAILURE);
    }
    data->player = malloc(sizeof(t_player));
    if (!data->player)
    {
        free_data(data);
        exit(EXIT_FAILURE);  
    }
}


static void	init_floor_ceiling(int *color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		color[i] = -1;
		i++;
	}
}


void init(t_data *data)
{
    data->texture->north_texture = NULL;
    data->texture->south_texture = NULL;
    data->texture->west_texture = NULL;
    data->texture->east_texture = NULL;
    data->counter->count_no = 0;
    data->counter->count_so = 0;
    data->counter->count_we = 0;
    data->counter->count_ea = 0;
    data->counter->count_f = 0;
    data->counter->count_c = 0;
    data->map->file_content = NULL;
    data->map->map = NULL;
    init_floor_ceiling(data->map->ceiling_color);
    init_floor_ceiling(data->map->floor_color);
    data->map->map_start_index = 0;
    data->map->width = 0;
    data->map->height = 0;
    data->player->player_pos_x = 1;
    data->player->player_pos_y = 1;
    data->player->angle = 0.0;

}

