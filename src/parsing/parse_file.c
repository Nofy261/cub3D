/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:03:27 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/02 09:14:45 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void load_texture(char *line, mlx_texture_t **texture, t_data *data)
{
    char **file;// le fichier
	
	file = ft_split(line, ' '); // on split la premiere ligne
    if (!file || !file[1])
        exit_error_with_array(data, file, "Invalid texture");
    *texture = mlx_load_png(file[1]);
    if (!*texture)
        exit_error_with_array(data, file, "loading path texture failed");
    free_array(file);
}


static void count_param(t_data *data, char *line)
{   
    int i;
    
    i = 0;
    //line = data->map->file_content[i]; // a voir utilité ici
    if (!data->map->file_content[0])
        exit_error(data, "map is empty");  
    while (data->map->file_content[i])
    {
        line = skip_whitespaces(data->map->file_content[i]);
        if (ft_strncmp(line, "NO ", 3) == 0)
            data->counter->count_no++;
        else if (ft_strncmp(line, "SO ", 3) == 0)
            data->counter->count_so++;
        else if (ft_strncmp(line, "WE ", 3) == 0)
            data->counter->count_we++;
        else if (ft_strncmp(line, "EA ", 3) == 0)
            data->counter->count_ea++;
        else if (ft_strncmp(line, "F ", 2) == 0)
            data->counter->count_f++;
        else if (ft_strncmp(line, "C ", 2) == 0)
            data->counter->count_c++;
        i++;
    }
}

static int check_invalid_element_and_map_start(t_data *data)
{
    int     i;
	char    *line;

    i = 0;
    while (data->map->file_content[i])
    {
        line = data->map->file_content[i];
        line = skip_whitespaces(line);
        if (line[0] == '1')
        {
            //data->map->map_start_index = 1;
            data->map->map_start_index = i; // modif 2 juin
            return (1);
        }
        if (line[0] != '\0' && ft_strncmp(line, "NO ", 3) != 0 && ft_strncmp(line, "SO ", 3) != 0 &&
            ft_strncmp(line, "WE ", 3) != 0 && ft_strncmp(line, "EA ", 3) != 0 && 
            ft_strncmp(line, "F ", 2) != 0 && ft_strncmp(line, "C ", 2) != 0)
            return (0);
        i++;
    }
    return (1);
}

// a voir si on met char *line dans prototype donc ajouter char *line dans le main pour gagner des lignes ici
void parse_and_load_textures(t_data *data)
{
    int     i;
	char    *line;
	
	i = 0;
    line = data->map->file_content[i];
    count_param(data, line);
    if (data->counter->count_no != 1 || data->counter->count_so != 1 ||
        data->counter->count_we != 1 || data->counter->count_ea != 1 ||
        data->counter->count_f != 1  || data->counter->count_c != 1)
        exit_error(data, "element in file invalid");
    if (check_invalid_element_and_map_start(data) == 0)
        exit_error(data, "found unknown element in file");
    if (data->map->map_start_index == 0)// ajout 2 juin
        exit_error(data, "Map start index not found");// ajout 2 juin
    while (i < data->map->map_start_index)
	{
        line = data->map->file_content[i];
        line = skip_whitespaces(line);
        if (ft_strncmp(line, "NO ", 3) == 0)
            load_texture(line, &data->texture->north_texture, data);
        else if (ft_strncmp(line, "SO ", 3) == 0)
            load_texture(line, &data->texture->south_texture, data);
        else if (ft_strncmp(line, "WE ", 3) == 0)
            load_texture(line, &data->texture->west_texture, data); 
        else if (ft_strncmp(line, "EA ", 3) == 0)
            load_texture(line, &data->texture->east_texture, data);
        i++;
    }
}


