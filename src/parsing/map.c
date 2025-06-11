/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:29:40 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 19:17:25 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_line_empty(const char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!is_whitespace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	find_last_map_line(char **lines, t_data *data)
{
	int	i;
	int	last;
	int	current;

	i = 0;
	last = -1;
	while (lines[i] != NULL)
	{
		if (is_line_empty(lines[i]))
		{
			current = i + 1;
			while (lines[current] != NULL)
			{
				if (!is_line_empty(lines[current]))
					exit_error_with_array(data, NULL, "Empty line inside map");
				current++;
			}
			break ;
		}
		last = i;
		i++;
	}
	return (last);
}

char	**map_start(t_data *data)
{
	int		start;
	int		last;
	int		size;
	char	**result;

	start = data->map.map_start_index;
	last = find_last_map_line(data->map.file_content + start, data);
	if (last < 0)
		exit_error_with_array(data, NULL, "No valid map lines found");
	size = last + 1;
	result = malloc(sizeof(char *) * (size + 1));
	if (result == NULL)
		exit_error_with_array(data, NULL, "Map allocation failed");
	start = 0;
	while (start < size)
	{
		result[start] = ft_strdup(
				data->map.file_content[data->map.map_start_index + start]);
		if (result[start] == NULL)
			exit_error_with_array(data, result, "Map copy failed");
		start++;
	}
	result[start] = NULL;
	return (result);
}

void	check_player(t_data *data)
{
	int		row;
	int		col;
	int		count;
	char	**map;

	count = 0;
	row = 0;
	map = data->map.map;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'N'
				|| map[row][col] == 'S'
				|| map[row][col] == 'E'
				|| map[row][col] == 'W')
				count++;
			col++;
		}
		row++;
	}
	if (count != 1)
		exit_error_with_array(data, NULL, "Invalid number of player");
}

void	player_start_position(t_data *data)
{
	int		row;
	int		col;
	char	**map;

	row = 0;
	map = data->map.map;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'N'
				|| map[row][col] == 'S'
				|| map[row][col] == 'E'
				|| map[row][col] == 'W')
			{
				data->player.pos_y = row + 0.5;
				data->player.pos_x = col + 0.5;
				set_player_angle_from_facing(data, map[row][col]);
				return ;
			}
			col++;
		}
		row++;
	}
}
