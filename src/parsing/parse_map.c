/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:22:36 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/03 11:31:50 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void check_valid_element(t_data *data)
{
    char    **map;
    int     i;
    int     j;
    int     count;

    count = 0;
    i = 0;
    map = data->map->map;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N' &&
                map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != ' ')
                exit_error_with_array(data, map, "Found invalid element in map");
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
                count++;
            j++;
        }
        i++;
    }
    if (count != 1)
        exit_error_with_array(data, map, "Invalid number of player");
    return ;
}


static void check_if_rectangular(t_data *data)
{
    int     i;
    char    **map;
    int     line_length;
    
    i = 0;
    map = data->map->map;
    line_length = ft_strlen(map[0]);
    while(map[i])
    {
        if (ft_strlen(map[i]) != line_length)
            exit_error_with_array(data, map, "Map is not rectangular");
        i++;
    }   
}

// Map rectangulaire : Toutes les lignes doivent avoir la même longueur✅
// Un seul joueur ✅
// Caractères valides ✅
// Map fermée  ❌
// Pas de lignes vides au milieu ❌
// les lignes vides apres la map sont considerer comme erreur : a corriger❌



void parse_map(t_data *data)
{
    char **map;
    int i;
    
    //skip_whitespaces();
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
    check_if_rectangular(data);
    check_valid_element(data); 
    // Si tout est bon, stocker la map dans structure data
    // data->map->map = map;
    // data->map->width = line_length;
}
