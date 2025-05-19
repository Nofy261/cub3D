/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:51:25 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/19 16:09:10 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// alloue un nouveau tableau (de la taille de l'ancien tab + 2)
// copie tout le contenu de l ancien tableau dans ce nouveau tableau
// allocation d'une place pour recuperer la prochaine ligne a lire
// return un tableau de tableau avec une place en memoire vide pret a stocker la prochaine ligne a lire
static char **add_line_to_tab(char **old_tab, int size_old_tab)
{
    // int size_old_tab = taille actuelle du tableau 
	char **new_tab;
	int i;
	
	new_tab = malloc(sizeof(char *) * (size_old_tab + 2));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (i < size_old_tab)
	{
		new_tab[i] = ft_strdup(old_tab[i]);
		if (!new_tab[i])
		{
			while (--i >= 0)
				free(new_tab[i]);
			free(new_tab);
			free_array(old_tab); 
			return (NULL);
		}
		i++;
	}
	new_tab[i] = NULL;
	new_tab[i + 1] = NULL;
	free_array(old_tab);
	return (new_tab);
}


char **get_file_content(int fd)
{
	int size;// compte le nombre de ligne dans result
	char **result;
	char *line;

	size = 0;
	result = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		result = add_line_to_tab(result, size);
		if (result == NULL)
		{
			free(line);
			break ;
		}
		result[size] = ft_strdup(line);
		if (!result[size])
		{
			free(line);
			break ;
		}
		size++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (result);
}




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
    // Split la 1ere ligne;
    char **tab;
	
	tab = ft_split(line, ' ');
    if (!tab || !tab[1])
	{
        ft_putstr_fd("Error: Invalid texture line\n", 2);
        free_array(tab);
        return;
    }
    // Charge la texture avec le chemin trouvé dans arr[1]
    *texture = mlx_load_png(tab[1]);
    
    if (!*texture)
        ft_putstr_fd("Error loading texture\n", 2);
    
    free_array(tab);
}


void parsing_file_path_textures(t_data *data)
{
    int i;
	char *line;
	
	i = 0;
    // Parcours chaque ligne du fichier
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