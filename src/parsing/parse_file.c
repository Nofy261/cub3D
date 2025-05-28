/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:03:27 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/28 13:17:18 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// A faire : verifier s'il y a tous les elements
// verifier si les elements ne reviennent pas deux fois


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
    // on charge la texture avec le chemin trouvé dans file[1]
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
    char **line;

    i = 0;
    line = data->map->file_content;
    if (!line[0])
    {
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd("map is empty\n", 2);
        //free tout ce qui a ete allouer avant
        exit (EXIT_FAILURE);
    }   
    while (data->map->file_content[i])
    {
        line[i] = skip_whitespaces(line[i]);
        if (ft_strncmp(line[i], "NO ", 3) == 0)
            data->counter->count_no++;
        else if (ft_strncmp(line[i], "SO ", 3) == 0)
            data->counter->count_so++;
        else if (ft_strncmp(line[i], "WE ", 3) == 0)
            data->counter->count_we++;
        else if (ft_strncmp(line[i], "EA ", 3) == 0)
            data->counter->count_ea++;
        else if (ft_strncmp(line[i], "F ", 2) == 0)
            data->counter->count_f++;
        else if (ft_strncmp(line[i], "C ", 2) == 0)
            data->counter->count_c++;
        i++;
    }
}

// fonction qui verifie les elements non autorisé dans le fichier
// A REGLER !! ne marche pas car considere les espaces vide comme erreur
static void check_unknown_element_in_file(t_data *data)
{
    int     i;
	char    **line;
	
	i = 0;
    line = data->map->file_content;
    while (data->map->file_content[i]) 
	{
        line[i] = skip_whitespaces(line[i]);
        if (line[i][0] == '\0')
        {
            if (ft_strncmp(line[i], "NO ", 3) != 0 && ft_strncmp(line[i], "SO ", 3) != 0 &&
                ft_strncmp(line[i], "WE ", 3) != 0 && ft_strncmp(line[i], "EA ", 3) != 0 &&
               ft_strncmp(line[i], "F ", 2) != 0 && ft_strncmp(line[i], "C ", 2) != 0)
            {
               ft_putstr_fd("Error\n", 2);
               ft_putstr_fd("unknown element in file\n", 2);
              //free tout
              exit(EXIT_FAILURE);
            }
        }
        i++;
    }
}


void parsing_file_path_textures(t_data *data)
{
    int     i;
	char    *line;
	
	i = 0;
    count_param(data);
    if (data->counter->count_no != 1 || data->counter->count_so != 1 ||
        data->counter->count_we != 1 || data->counter->count_ea != 1 ||
        data->counter->count_f != 1  || data->counter->count_c != 1)
        {
            ft_putstr_fd("Error\n", 2);
            ft_putstr_fd("element in file invalid\n", 2);
            //free tout
            exit(EXIT_FAILURE);
        }
    check_unknown_element_in_file(data);
    while (data->map->file_content[i]) 
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

// a faire fonction qui gere le message + exit pour eviter repetition
// static void exit_error(t_data *data)
// {

//   if (
//     {
//         ft_putstr_fd("Error\n", 2);
//         ft_putstr_fd("map is empty\n", 2);
//         //free tout ce qui a ete allouer avant
//         exit (EXIT_FAILURE);
//     } 
// }