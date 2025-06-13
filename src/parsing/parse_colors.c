/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:12:57 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/13 10:46:54 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_rgb_format(char *str, t_data *data)
{
	int	i;
	int	commas;

	i = 0;
	commas = 0;
	while (str[i])
	{
		if (str[i] == ',')
			commas++;
		if (commas > 2
			|| (!ft_isdigit(str[i]) && str[i] != ',')
			|| (str[i] == ',' && is_whitespace(str[i - 1]))
			|| (str[i] == ',' && is_whitespace(str[i + 1])))
			exit_error(data, "Invalid color format");
		i++;
	}
}

static int	parse_rgb_values(char **parts, int *r, int *g, int *b)
{
	*r = ft_atoi(parts[0]);
	*g = ft_atoi(parts[1]);
	*b = ft_atoi(parts[2]);
	if (*r < 0 || *r > 255
		|| *g < 0 || *g > 255
		|| *b < 0 || *b > 255)
		exit_error_with_array(NULL, parts, "Color value invalid");
	return (1);
}

static void	assign_color(int *dst, int r, int g, int b)
{
	dst[0] = r;
	dst[1] = g;
	dst[2] = b;
}

static void	parse_color_line(t_data *data, char *str, int floor_flag)
{
	char	**file;
	int		r;
	int		g;
	int		b;

	validate_rgb_format(str, data);
	file = ft_split(str, ',');
	if (file == NULL
		|| file[0] == NULL
		|| file[1] == NULL
		|| file[2] == NULL
		|| file[3] != NULL)
		exit_error_with_array(data, file, "Invalid color format");
	parse_rgb_values(file, &r, &g, &b);
	if (floor_flag)
		assign_color(data->map.floor_color, r, g, b);
	else
		assign_color(data->map.sky_color, r, g, b);
	free_array(file);
}

void	parse_file_colors(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	while (data->map.file_content[i] != NULL)
	{
		line = skip_whitespaces(data->map.file_content[i]);
		if (ft_strncmp(line, "F ", 2) == 0)
			parse_color_line(data, line + 2, 1);
		else if (ft_strncmp(line, "C ", 2) == 0)
			parse_color_line(data, line + 2, 0);
		i++;
	}
}
