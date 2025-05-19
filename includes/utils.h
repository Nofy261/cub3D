/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:02:00 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/19 11:10:01 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"



//UTILS.C
void ft_putstr_fd(char *str, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void free_array(char **array);















#endif