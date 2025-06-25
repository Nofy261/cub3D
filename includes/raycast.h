/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:56:20 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/26 00:57:37 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

// RAYSTART.C
void	start_game(t_data *data);

//	MOVEMENT.C
int		handle_collision(t_data *data, double orientation, double delta_time);
void	rotate_camera(t_data *data, double angle);

//	INPUT.C
void	handle_input_hooks(t_data *data);

//	RENDER.C
int		render_frame(void *param);

//	DRAW.C
void	draw_background(t_data *data, int x);
void	draw_wall(t_data *data, int x, t_ray *ray);

//	RAYCAST.C
void	raycast_loop(t_data *data);

// UTILS.C
void	set_player_angle_from_facing(t_data *data, char facing);
double	get_time(void);

#endif