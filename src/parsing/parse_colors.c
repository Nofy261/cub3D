/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:12:57 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/28 08:41:40 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_color(char *rgb)
{
	int i;
    
    i = 0;
	while (rgb[i])
	{
		if (!ft_isdigit(rgb[i]) && rgb[i] != ',')
			return (0);
        // gere le cas de double virgule (224,,122,0)
		if (rgb[i] == ',' && (i == 0 || !ft_isdigit(rgb[i - 1]) || !ft_isdigit(rgb[i + 1])))
			return (0);
		i++;
	}
	return (1);
}


static int	convert_and_check_rgb(char **colors, int *r, int *g, int *b)
{
    *r = ft_atoi(colors[0]);
    *g = ft_atoi(colors[1]);
    *b = ft_atoi(colors[2]);
    if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
    {
        ft_putstr_fd("Error: Color value is invalid\n", 2);
        free_array(colors);
        return (0);
    }
    return (1);
}

static void set_color(int *color, int r, int g, int b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}


static void parse_color_line(t_data *data, char *rgb, int is_floor)
{
    char **colors;
    int r;
    int g;
    int b;

    if (!is_valid_color(rgb))
        return; 
    colors = ft_split(rgb, ','); // on split "220,100,0"
    if (!colors || !colors[0] || !colors[1] || !colors[2] || colors[3])
    {
        ft_putstr_fd("Error: Invalid color format\n", 2);// plus de 3couleurs
        free_array(colors);
        return;
    }
    if (convert_and_check_rgb(colors, &r, &g, &b) == 0)
        return ;
    if (is_floor)
        set_color(data->map->floor_color, r, g, b);
    else
        set_color(data->map->ceiling_color, r, g, b);
    free_array(colors);
}


void parse_file_colors(t_data *data)
{
    int i;
    char *line;
    
    i = 0;
    while (data->map->file_content[i])
    {
        line = data->map->file_content[i];
        line = skip_whitespaces(line);
        if (ft_strncmp(line, "F ", 2) == 0)
            parse_color_line(data, skip_whitespaces(line + 1), 1);
        else if (ft_strncmp(line, "C ", 2) == 0)
            parse_color_line(data, skip_whitespaces(line + 1), 0);
        i++;
    }
}

//  if (is_floor)
//     {
//         data->map->floor_color[0] = r;
//         data->map->floor_color[1] = g;
//         data->map->floor_color[2] = b;
//     }
//     else
//     {
//         data->map->ceiling_color[0] = r;
//         data->map->ceiling_color[1] = g;
//         data->map->ceiling_color[2] = b;
//     }