/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:01:35 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/12 10:03:58 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	fd = parse_args_open_file(argc, argv);
	init(&data);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		exit_error(&data, "Failed to init MLX");
	data.map.file_content = get_file_content(fd);
	close(fd);
	parse_and_load_textures(&data);
	parse_file_colors(&data);
	data.map.map = map_start(&data);
	parse_map(&data);
	player_start_position(&data);
	start_game(&data);
	free_data(&data);
	return (0);
}
