/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:51:25 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 18:44:33 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**expand_tab(char **old_tab, int old_size)
{
	char	**new_tab;
	int		i;

	new_tab = malloc(sizeof(char *) * (old_size + 2));
	if (new_tab == NULL)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		new_tab[i] = ft_strdup(old_tab[i]);
		if (new_tab[i] == NULL)
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

static int	store_line(char ***res_ptr, int i, char *line)
{
	char	**tmp;

	tmp = expand_tab(*res_ptr, i);
	if (tmp == NULL)
	{
		free(line);
		return (0);
	}
	*res_ptr = tmp;
	(*res_ptr)[i] = ft_substr(line, 0, ft_strcspn(line, "\n"));
	if ((*res_ptr)[i] == NULL)
	{
		free(line);
		return (0);
	}
	return (1);
}

char	**get_file_content(int fd)
{
	int		count;
	char	**res;
	char	*line;

	count = 0;
	res = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!store_line(&res, count, line))
			break ;
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (res);
}
