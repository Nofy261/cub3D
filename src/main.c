/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:01:35 by nolecler          #+#    #+#             */
/*   Updated: 2025/07/02 13:11:51 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	init(&data);
	data.fd = parse_args_open_file(argc, argv);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		exit_error(&data, "Failed to init MLX");
	data.map.file_content = get_file_content(data.fd);
	close(data.fd);
	data.fd = 0;
	parse_and_load_textures(&data);
	parse_file_colors(&data);
	data.map.map = map_start(&data);
	parse_map(&data);
	player_start_position(&data);
	start_game(&data);
	return (0);
}
