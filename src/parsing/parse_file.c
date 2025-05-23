/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:03:27 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/23 12:18:50 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// A faire : verifier s'il y a tous les elements
// verifier si les elements ne reviennent pas deux fois


char	*skip_whitespaces(char *str)
{  
    while (str && is_whitespace(*str))
        str++;   
    return (str);
}


static void load_texture(char *line, mlx_texture_t **texture)
{
    char **file;// le fichier
	
	file = ft_split(line, ' '); // on split la premiere ligne
    if (!file || !file[1])
	{
        ft_putstr_fd("Error: Invalid texture\n", 2);
        free_array(file);
        return;
    }
    // on charge la texture avec le chemin trouvé dans file[1]
    *texture = mlx_load_png(file[1]);
    if (!*texture)
        ft_putstr_fd("Error loading texture\n", 2);
    free_array(file);
}


void parsing_file_path_textures(t_data *data)
{
    int i;
	char *line;
	
	i = 0;
    // on parcours chaque ligne du fichier
    while (data->map->file_content[i]) 
	{
        line = data->map->file_content[i];
        line = skip_whitespaces(line);
        if (ft_strncmp(line, "NO ", 3) == 0)
            load_texture(line, &data->texture->north_texture);
        else if (ft_strncmp(line, "SO ", 3) == 0)
            load_texture(line, &data->texture->south_texture);
        else if (ft_strncmp(line, "WE ", 3) == 0)
            load_texture(line, &data->texture->west_texture); 
        else if (ft_strncmp(line, "EA ", 3) == 0)
            load_texture(line, &data->texture->east_texture);
        i++;
    }
}
