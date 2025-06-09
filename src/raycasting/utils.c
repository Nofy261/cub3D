/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:14:38 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/09 15:15:40 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_angle_from_facing(t_data *data, char facing)
{
	if (facing == 'N') // si le joueur regarde vers le nord
		data->player->angle = 3 * M_PI / 2; // je lui donne l'angle associe a cette direction 
	else if (facing == 'S')
		data->player->angle = M_PI / 2;
	else if (facing == 'E')
		data->player->angle = 0;
	else if (facing == 'W')
		data->player->angle = M_PI;
}

