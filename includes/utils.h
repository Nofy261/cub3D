/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:02:00 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/31 13:14:46 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"



//UTILS_0.C
void ft_putstr_fd(char *str, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int	is_whitespace(char c);
int	ft_atoi(const char *nptr);


// UTILS_1.c
char	**ft_split(char const *s, char c);

// UTILS_2.c
int	ft_isdigit(int c);
int	ft_strcspn(char *line, char *str);
char	*skip_whitespaces(char *str);
void	exit_error(t_data *data, char *msg);
void	exit_error_with_array(t_data *data, char **array, char *msg);


// FREE.C
void free_array(char **array);
void free_textures(t_data *data);
void free_data(t_data *data);


















#endif