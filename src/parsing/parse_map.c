/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:22:36 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/06 15:39:19 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void check_valid_element(t_data *data)
{
    char **map;
    int i;
    int j;

    i = 0;
    map = data->map->map;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N' &&
                map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W' &&
                map[i][j] != ' ')
                exit_error_with_array(data, NULL, "Found invalid element in map");
            j++;
        }
        i++;
    }
    return;
}

static int is_in_set(char c, char *set)
{
    while (*set)
    {
        if (*set == c)
            return (1);
        set++;
    }
    return (0);
}

// ligne par ligne : autour de whitespace = 1 ou autre whitespace sinon erreur

static int is_case_valid(char **map, int i, int j)
{
    if (i <= 0 || j <= 0 || !map[i + 1] || !map[i][j + 1]) // rajout 6 june
        return (0);
    if (is_in_set(map[i][j + 1], "10NSEW") && is_in_set(map[i - 1][j], "10NSEW") &&
        is_in_set(map[i + 1][j], "10NSEW") && is_in_set(map[i][j - 1], "10NSEW"))
    {
        return (1);
    }
    return (0);
}

static int is_map_closed(t_data *data)
{
    int i;
    int j;
    char **map;

    j = 0;
    i = data->map->map_start_index;
    map = data->map->file_content;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' ||
                map[i][j] == 'E' || map[i][j] == 'W') // modif 6 june
            {
                if (j == 0)
                    return (0);
                if (!is_case_valid(map, i, j))
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

void parse_map(t_data *data)
{
    char **map;
    int i;

    map = data->map->map;
    if (!map || !map[0])
        exit_error_with_array(data, map, "Map doesn't exist");
    i = 0;
    while (map[i])
    {
        if (map[i][0] == '\0')
            exit_error_with_array(data, map, "Empty line in map");
        i++;
    }
    check_valid_element(data);
    check_player(data);
    if (!is_map_closed(data))
        exit_error_with_array(data, NULL, "Map unclosed");
    player_start_position(data);
}
