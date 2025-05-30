/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:03:27 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/30 15:22:07 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void load_texture(char *line, mlx_texture_t **texture, t_data *data)
{
    char **file;// le fichier
	
	file = ft_split(line, ' '); // on split la premiere ligne
    if (!file || !file[1])
	{
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd("Invalid texture\n", 2);
        free_array(file);
        free_data(data);
        exit(EXIT_FAILURE);
    }
    *texture = mlx_load_png(file[1]);
    if (!*texture)
    {
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd("loading path texture failed\n", 2);
        free_array(file);
        free_data(data);
        exit(EXIT_FAILURE);  
    }
    free_array(file);
}


static void count_param(t_data *data)
{   
    int i;
    char *line;

    i = 0;
    line = data->map->file_content[i];
    if (!data->map->file_content[0])
    {
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd("map is empty\n", 2);
        free_data(data);
        exit (EXIT_FAILURE);
    }   
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
            data->map->map_start_index = 1;
            return (1);
        }
        if (ft_strncmp(line, "NO ", 3) != 0 && ft_strncmp(line, "SO ", 3) != 0 &&
            ft_strncmp(line, "WE ", 3) != 0 && ft_strncmp(line, "EA ", 3) != 0 && 
            ft_strncmp(line, "F ", 2) != 0 && ft_strncmp(line, "C ", 2) != 0 && 
            line[0] != '\0')
            return (0);
        i++;
    }
    return (1);
}


void parse_and_load_textures(t_data *data)
{
    int     i;
	char    *line;
	
	i = 0;
    line = data->map->file_content[i];
    count_param(data);
    if (data->counter->count_no != 1 || data->counter->count_so != 1 ||
        data->counter->count_we != 1 || data->counter->count_ea != 1 ||
        data->counter->count_f != 1  || data->counter->count_c != 1)
    {
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd("element in file invalid\n", 2);
        free_data(data);
        exit(EXIT_FAILURE);
    }
    if (check_invalid_element_and_map_start(data) == 0)
    {
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd("found unknown element in file\n", 2);
        free_data(data);
        exit(EXIT_FAILURE);
    }
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
