/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:46:25 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/30 14:19:08 by nolecler         ###   ########.fr       */
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




// PARSE_FILE
void parse_and_load_textures(t_data *data);













#endif