/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:12:57 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/02 09:22:25 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//❌ ATTENTION Les espaces dans le path ne sont plus considerer comme erreur a cause d'ajout de condition dans parse_color
// erreur dans parse_file a gerer quand on met les esapces dans le chemin ❌
// espaces apres le dernier chiffres a gerer comme pas erreur ❌

static int	is_valid_color(char *rgb, t_data *data)
{
	int i;
    int count_comma;

    i = 0;
    count_comma = 0;
	while (rgb[i])
	{
        if (rgb[i] == ',')
            count_comma++;
        if (count_comma > 2 || (is_whitespace(rgb[i]) == 1) || (!ft_isdigit(rgb[i]) && rgb[i] != ',') ||
            (rgb[i] == ',' && is_whitespace(rgb[i - 1]) == 1) ||
            (rgb[i] == ',' && is_whitespace(rgb[i + 1]) == 1))
            exit_error(data, "invalid color format");
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
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd("Color value is invalid\n", 2);
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

    is_valid_color(rgb, data);
    colors = ft_split(rgb, ','); // on split "220,100,0"
    if (!colors || !colors[0] || !colors[1] || !colors[2] || colors[3])
        exit_error_with_array(data, colors, "Invalid color format");
    if (convert_and_check_rgb(colors, &r, &g, &b) == 0)
    {
        free_data(data);
        exit(EXIT_FAILURE);
    }
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