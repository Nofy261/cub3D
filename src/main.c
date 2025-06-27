/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:01:35 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/27 10:29:48 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	ft_bzero(&data, sizeof(data));
	fd = parse_args_open_file(argc, argv);
	init(&data);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
	{
		close(fd);
		exit_error(&data, "Failed to init MLX");
	}
	data.map.file_content = get_file_content(fd);
	close(fd);
	parse_and_load_textures(&data);
	parse_file_colors(&data);
	data.map.map = map_start(&data);
	parse_map(&data);
	player_start_position(&data);
	start_game(&data);
	return (0);
}
