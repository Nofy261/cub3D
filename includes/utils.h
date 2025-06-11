/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:02:00 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 19:42:12 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

// EXIT.C
void	exit_error(t_data *data, char *msg);
void	exit_error_with_array(t_data *data, char **array, char *msg);

// FREE.C
void	free_array(char **array);
void	free_textures(t_data *data);
void	free_data(t_data *data);

// STRING.C
int		char_in_set(char c, const char *set);
int		is_whitespace(char c);
int		ft_strcspn(char *line, char *str);
char	*skip_whitespaces(char *str);

#endif