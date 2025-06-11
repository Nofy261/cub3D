/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:03:27 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 15:04:18 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void load_texture(char *line, t_texture *texture, t_data *data)
{
    char **file;

    file = ft_split(line, ' ');
    if (!file || !file[1])
        exit_error_with_array(data, file, "Invalid texture path");

    texture->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
                                             file[1],
                                             &texture->width,
                                             &texture->height);
    if (!texture->img_ptr)
        exit_error_with_array(data, file, "Failed to load texture");

    texture->data = mlx_get_data_addr(texture->img_ptr,
                                      &texture->bpp,
                                      &texture->size_line,
                                      &texture->endian);
    free_array(file);
}


static void count_param(t_data *data)
{
    int  i;
    char *line;

    i = 0;
    if (!data->map.file_content || !data->map.file_content[0])
        exit_error(data, "Map is empty");

    while (data->map.file_content[i])
    {
        line = skip_whitespaces(data->map.file_content[i]);
        if      (ft_strncmp(line, "NO ", 3) == 0) data->counter.count_no++;
        else if (ft_strncmp(line, "SO ", 3) == 0) data->counter.count_so++;
        else if (ft_strncmp(line, "WE ", 3) == 0) data->counter.count_we++;
        else if (ft_strncmp(line, "EA ", 3) == 0) data->counter.count_ea++;
        else if (ft_strncmp(line, "F ",  2) == 0) data->counter.count_f++;
        else if (ft_strncmp(line, "C ",  2) == 0) data->counter.count_c++;
        i++;
    }
}

static int check_invalid_element_and_map_start(t_data *data)
{
    int  i;
    char *line;

    i = 0;
    while (data->map.file_content[i])
    {
        line = skip_whitespaces(data->map.file_content[i]);
        if (line[0] == '1')
        {
            data->map.map_start_index = i;
            return (1);
        }
        if (line[0] != '\0'
         && ft_strncmp(line, "NO ", 3) != 0
         && ft_strncmp(line, "SO ", 3) != 0
         && ft_strncmp(line, "WE ", 3) != 0
         && ft_strncmp(line, "EA ", 3) != 0
         && ft_strncmp(line, "F ",  2) != 0
         && ft_strncmp(line, "C ",  2) != 0)
            return (0);
        i++;
    }
    return (1);
}

// a voir si on met char *line dans prototype donc ajouter char *line dans le main pour gagner des lignes ici
void parse_and_load_textures(t_data *data)
{
    int  i;
    char *line;

    i = 0;
    count_param(data);
    if (data->counter.count_no != 1  || data->counter.count_so != 1 ||
        data->counter.count_we != 1  || data->counter.count_ea != 1 ||
        data->counter.count_f  != 1  || data->counter.count_c  != 1)
        exit_error(data, "Invalid number of elements");

    if (!check_invalid_element_and_map_start(data))
        exit_error(data, "Unknown element in file");

    if (data->map.map_start_index == 0)
        exit_error(data, "Map start index not found");

    while (i < data->map.map_start_index)
    {
        line = skip_whitespaces(data->map.file_content[i]);
        if      (ft_strncmp(line, "NO ", 3) == 0) load_texture(line, &data->north_texture, data);
        else if (ft_strncmp(line, "SO ", 3) == 0) load_texture(line, &data->south_texture, data);
        else if (ft_strncmp(line, "WE ", 3) == 0) load_texture(line, &data->west_texture,  data);
        else if (ft_strncmp(line, "EA ", 3) == 0) load_texture(line, &data->east_texture,  data);
        i++;
    }
}


