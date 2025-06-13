/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:09:53 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/13 15:06:55 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "cub3d.h"

// Uniquement pour vscode mac (c'est galère)
#ifndef M_PI
#  define M_PI 3.14159265358979323846
#endif

#ifndef RGB
# define RGB(r,g,b)  (((r) << 16) | ((g) << 8) | (b))
#endif

typedef struct s_texture
{
	void	*image;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_texture;

typedef struct s_counter
{
	int	count_no;
	int	count_so;
	int	count_we;
	int	count_ea;
	int	count_f;
	int	count_c;
}	t_counter;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_map
{
	char	**file_content;
	int		floor_color[3];
	int		sky_color[3];
	int		map_start_index;
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_texture	screen;
	t_texture	north_texture;
	t_texture	south_texture;
	t_texture	west_texture;
	t_texture	east_texture;
	t_map		map;
	t_counter	counter;
	t_player	player;
	int			key_up;
	int			key_down;
	int			key_left;
	int			key_right;
}	t_data;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_dist;
}	t_ray;

#endif