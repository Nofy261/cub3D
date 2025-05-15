/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:51:25 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/15 15:05:26 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// recup ligne par ligne puis parser
// on recuperer d abord les orientations
// puis on recupere la map ?? 
// le fichier est ouvert
// on va recuperer ligne par ligne


char **add_line_to_tab(char **old_tab, int size)
{
    // int size = nombre de lignes
	char **new_tab;
	int i;

    // alloue un nouveau tab pour avoir une ligne en plus
	new_tab = malloc(sizeof(char *) * (size + 2));
	if (!new_tab)
		return (NULL);
	i = 0;
    // Copie chaque ligne de l'ancien tableau dans le nouveau tableau
	while (i < size)
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


char **get_file(int fd)
{
    char *line;
    char **dest;

    
    line = get_next_line(fd);
    while (line)
    {
        
        dest = add_line_to_tab()
    }

    
}