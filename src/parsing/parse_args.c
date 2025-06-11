/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:51:22 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 18:29:00 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_arg_count(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
}

static void	validate_extension(const char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5
		|| ft_strncmp(path + len - 4, ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid file extension\n", 2);
		exit(EXIT_FAILURE);
	}
}

static int	open_cub_file(const char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Path is a directory\n", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Failed to open file\n", 2);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	parse_args_open_file(int argc, char **argv)
{
	int	fd;

	validate_arg_count(argc);
	if (argv == NULL || argv[1] == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Missing file argument\n", 2);
		exit(EXIT_FAILURE);
	}
	validate_extension(argv[1]);
	fd = open_cub_file(argv[1]);
	return (fd);
}
