/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:29:40 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/03 15:39:44 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int is_line_empty(char *line)
{
    int i;
    
    i = 0;
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
            return (0);// la ligne n est pas vide
        i++;
    }
    return (1); // la ligne est vide
}

// recupere l'index de la derniere ligne et
// verifie s il y a une ligne vide a l interieur de la map
static int find_last_map_line(char **lines, t_data *data)
{
    int i;
    int last_line;
    int j;
    
    i = 0;
    j = 0;
    last_line = -1;
    while (lines[i])
    {
        if (is_line_empty(lines[i]))
        {
            j = i + 1;
            while (lines[j])
            {
                if (is_line_empty(lines[j]) == 0)
                    exit_error_with_array(data, NULL, "Empty line inside map");// ligne non vide trouvee apres une ligne vide
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

// retourne juste que la map
char **map_start(t_data *data)
{
    int     j;
    int     i;
    int     last_valid;
    int     total_map_line;
    char    **map;
    
    i = data->map->map_start_index;
    last_valid = find_last_map_line(data->map->file_content + i, data);
    if (last_valid == -1)
        exit_error_with_array(data, NULL, "No valid map lines found");
    total_map_line = last_valid + 1;// +1 ligne de la fin 
    map = malloc(sizeof(char *) * (total_map_line + 1));
    if (!map)
        exit_error_with_array(data, map, "Map allocation failed");
    j = 0;
    while (j < total_map_line)
    {
        map[j] = ft_strdup(data->map->file_content[i + j]);
        if (!map[j])
           exit_error_with_array(data, map, "Map copy failed"); 
        j++;
    }
    map[j] = NULL;
    return (map);
}



