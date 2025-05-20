/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:51:25 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/20 08:03:55 by nolecler         ###   ########.fr       */
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

