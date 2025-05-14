/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:51:22 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/14 11:26:17 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


static void pars_args(int argc, char **argv)
{
	int len;
	
	len = ft_strlen(argv[1]);
	if (argc != 2)
	{
		ft_putstr_fd("Error: number of argument is invalid\n", 2);
		exit(EXIT_FAILURE);
	}
	if(len < 4 || ft_strncmp(&argv[1][len - 4], ".cub", 4) != 0)
	{
		ft_putstr_fd("Error: file extension is invalid\n", 2);
		exit(EXIT_FAILURE);
	}
	//else
		//fonction qui ouvre et lit le fichier
}

// fonction qui ouvre et lit le fichier
// on ouvre
// on lit
void open_read_file(char **argv)
{
	

	
}