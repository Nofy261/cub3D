/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:20:42 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/30 15:13:47 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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


