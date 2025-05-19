/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:01:35 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/19 10:45:29 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int main(int argc, char **argv)
{
	int i = 0;
	int fd;
	char **result;
	
	fd = open_file(argv);
	parse_args(argc, argv);
	result = get_file_content(fd);
	
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	free_array(result);
	return (0);
}



