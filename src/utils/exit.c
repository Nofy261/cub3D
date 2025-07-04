/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:20:42 by nolecler          #+#    #+#             */
/*   Updated: 2025/07/04 15:45:34 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(t_data *data, char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	free_data(data);
	exit(EXIT_FAILURE);
}

void	exit_error_with_array(t_data *data, char **array, char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	if (array)
	{
		if (array == data->map.map)
			data->map.map = NULL;
		free_array(array);
	}
	free_data(data);
	exit(EXIT_FAILURE);
}
