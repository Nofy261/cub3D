/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:56:20 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 19:46:17 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

// RAYSTART.C
void	start_game(t_data *data);
void	handle_collision(t_data *data, double orient);

// RAYCAST.C
int		render_frame(void *param);

// UTILS.C
void	set_player_angle_from_facing(t_data *data, char facing);

#endif