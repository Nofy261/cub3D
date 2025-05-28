/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:02:00 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/28 10:50:59 by nolecler         ###   ########.fr       */
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
void free_array(char **array);
int	is_whitespace(char c);
int	ft_atoi(const char *nptr);


// UTILS_1.c
char	**ft_split(char const *s, char c);

// UTILS_2.c
void free_data(t_data *data);
int	ft_isdigit(int c);
int	ft_strcspn(char *line, char *str);
char	*skip_whitespaces(char *str);
















#endif