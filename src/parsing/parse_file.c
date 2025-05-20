/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:03:27 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/20 08:31:35 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// verifier si c est bien NO SO WE EA
// si c est le cas je split la ligne " NO ./texture/path_to_north"
// j aurais : tab[0] = "NO", et tab[1] = "./texture/path_to_north"
// tab[1] est le chemin et je le recupere 
// ensuite j envoie ce path a mlx_load_png("./texture/path_to_north");
// ensuite je le donne a ma structure de texture pour la stocker
// data->texture->north_texture = mlx_load_png("./texture/path_to_north")
// ou data->texture->north_texture = mlx_load_png("tab[1]");


void load_texture(char *line, mlx_texture_t **texture)
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
