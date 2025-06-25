/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:56:20 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/25 13:43:52 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

// RAYSTART.C
void	start_game(t_data *data);

//	COLLISION.C
int		handle_collision(t_data *data, double orientation, double delta_time);

// //	INPUT.C
void	handle_input_hooks(t_data *data);

//	RENDER.C
int	render_frame(void *param);
void	rotate_camera(t_data *data, double angle); // test ajout 24-06

//	RAYCAST.C
void	raycast_loop(t_data *data);

// UTILS.C
void	set_player_angle_from_facing(t_data *data, char facing);
double	get_time();
#endif