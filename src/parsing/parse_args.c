/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:51:22 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/27 09:02:23 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// on verifie si le fichier n est pas vide
// on verifie si ce n est pas un dossier
//int open_file(char **argv) // test
static int open_file(char **argv)
{
	int fd;

	fd = open(argv[1], O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		ft_putstr_fd("Error: Is a directory\n", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || fd > 1023)
	{
		ft_putstr_fd("Error: Failed to open the file\n", 2);
		exit(EXIT_FAILURE);
	}
	return (fd);
}


int parse_args_open_file(int argc, char **argv)
{
	int len;
	int fd;
	
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("number of argument is invalid\n", 2);
		exit(EXIT_FAILURE);
	}
	if (!argv || !argv[0] || !argv[1])
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("NO ARGV\n", 2);// message a modifier
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if(len < 4 || ft_strncmp(&argv[1][len - 4], ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("file extension is invalid\n", 2);
		exit(EXIT_FAILURE);
	}
	fd = open_file(argv); // a close !!!
	return (fd);
}

