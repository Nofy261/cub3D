/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:46:25 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/19 11:35:54 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"

// PARSE_ARGS.C
void parse_args_get_file(int argc, char **argv);




// PARSE_FILE.C
char **get_file_content(int fd);











#endif