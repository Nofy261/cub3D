/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:29:40 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 15:10:01 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int is_line_empty(char *line)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static int find_last_map_line(char **lines, t_data *data)
{
	int i = 0;
	int last_line = -1;
	int j;

	while (lines[i])
	{
		if (is_line_empty(lines[i]))
		{
			j = i + 1;
			while (lines[j])
			{
				if (!is_line_empty(lines[j]))
					exit_error_with_array(data, NULL, "Empty line inside map");
				j++;
			}
			break;
		}
		else
			last_line = i;
		i++;
	}
	return (last_line);
}

char **map_start(t_data *data)
{
	int     i = data->map.map_start_index;
	int     last_valid;
	int     total_map_line;
	int     j;
	char  **map;

	last_valid = find_last_map_line(data->map.file_content + i, data);
	if (last_valid < 0)
		exit_error_with_array(data, NULL, "No valid map lines found");

	total_map_line = last_valid + 1;
	map = malloc(sizeof(char *) * (total_map_line + 1));
	if (!map)
		exit_error_with_array(data, map, "Map allocation failed");

	j = 0;
	while (j < total_map_line)
	{
		map[j] = ft_strdup(data->map.file_content[i + j]);
		if (!map[j])
		   exit_error_with_array(data, map, "Map copy failed");
		j++;
	}
	map[j] = NULL;
	return (map);
}

void check_player(t_data *data)
{
	int     i = 0;
	int     j;
	int     count = 0;
	char  **map = data->map.map;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
			 || map[i][j] == 'E' || map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		exit_error_with_array(data, NULL, "Invalid number of player");
}

void player_start_position(t_data *data)
{
	int     i = 0;
	int     j;
	char  **map = data->map.map;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
			 || map[i][j] == 'E' || map[i][j] == 'W')
			{
				data->player.pos_y = i + 0.5;
				data->player.pos_x = j + 0.5;
				set_player_angle_from_facing(data, map[i][j]);
				return;
			}
			j++;
		}
		i++;
	}
}