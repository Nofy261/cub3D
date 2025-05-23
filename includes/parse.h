/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:46:25 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/23 08:53:26 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"

// GET_FILE.C
char **get_file_content(int fd);
char	*skip_whitespaces(char *str);

// PARSE_ARGS.C
int parse_args_open_file(int argc, char **argv);



// PARSE_COLORS.C




// PARSE_FILE
void parsing_file_path_textures(t_data *data);













#endif