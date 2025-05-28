/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:20:42 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/28 11:23:45 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_data(t_data *data)
{
    if (data->map)
    {
        if (data->map->file_content)
            free_array(data->map->file_content);
        free(data->map);
    }
	if (data->texture)
    	free(data->texture);
	if (data->counter)
		free(data->counter);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


int	ft_strcspn(char *line, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (str[j])
		{
			if (line[i] == str[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

char	*skip_whitespaces(char *str)
{  
    while (str && is_whitespace(*str))
        str++;   
    return (str);
}




