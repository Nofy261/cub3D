/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:01:35 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/21 15:28:08 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int main(int argc, char **argv)
{
	t_data data;
	int fd;
	
	fd = parse_args_open_file(argc, argv); // fd open ici a close si erreur de malloc
	allocate(&data);
	init(&data);
	data.map->file_content = get_file_content(fd);
	close(fd);// 
	parsing_file_path_textures(&data);


	
	free_data(&data);
	return (0);
}



