/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:46:25 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/06 15:39:59 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"

// GET_FILE.C
char **get_file_content(int fd);


// PARSE_ARGS.C
int parse_args_open_file(int argc, char **argv);



// PARSE_COLORS.C
void parse_file_colors(t_data *data);



// PARSE_FILE.C
void parse_and_load_textures(t_data *data);



// PARSE_MAP.C
void parse_map(t_data *data);


// MAP.C
char **map_start(t_data *data);
void check_player(t_data *data);
void player_start_position(t_data *data);














#endif