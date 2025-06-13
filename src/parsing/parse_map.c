/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:22:36 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 19:13:22 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_map_chars(char **map, t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (!char_in_set(map[row][col], "01NSEW "))
				exit_error_with_array(data, map, "Invalid map character");
			col++;
		}
		row++;
	}
}

static int	validate_closure(char **map, int row, int col)
{
	if (row <= 0
		|| col <= 0
		|| map[row + 1] == NULL
		|| map[row][col + 1] == '\0')
		return (0);
	if (!char_in_set(map[row][col + 1], "10NSEW")
		|| !char_in_set(map[row - 1][col], "10NSEW")
		|| !char_in_set(map[row + 1][col], "10NSEW")
		|| !char_in_set(map[row][col - 1], "10NSEW"))
		return (0);
	return (1);
}

static int	is_map_closed(t_data *data)
{
	char	**map;
	int		row;
	int		col;

	map = data->map.map;
	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (char_in_set(map[row][col], "0NSEW")
				&& !validate_closure(map, row, col))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

void	parse_map(t_data *data)
{
	char	**map;
	int		i;

	map = data->map.map;
	if (map == NULL || map[0] == NULL)
		exit_error_with_array(data, map, "Map is missing");
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] == '\0')
			exit_error_with_array(data, map, "Empty line in map");
		i++;
	}
	validate_map_chars(map, data);
	check_player(data);
	if (!is_map_closed(data))
		exit_error_with_array(data, NULL, "Map is not closed");
	player_start_position(data);
}
