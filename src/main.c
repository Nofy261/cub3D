/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:01:35 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/03 14:18:14 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data data;
	int fd;
	
	fd = parse_args_open_file(argc, argv); // fd open ici a close si erreur avant
	allocate(&data);
	init(&data);
	data.map->file_content = get_file_content(fd);
	//close(fd);// 
	parse_and_load_textures(&data);
	parse_file_colors(&data);
	data.map->map = map_start(&data);
	// Affichage pour vérif
	printf("====================\n");
	int i = 0;
	while (data.map->map[i])
	{
    	printf("%s\n", data.map->map[i]);
    	i++;
	}
	printf("====================\n");	
	parse_map(&data);
	free_data(&data);
	//close(fd);
	return (0);
}



