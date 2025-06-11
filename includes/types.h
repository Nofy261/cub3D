/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:09:53 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 15:30:56 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "cub3d.h"

// Uniquement pour vscode mac (c'est galère)
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_texture
{
	void    *img_ptr;
	char    *data;
	int     width;
	int     height;
	int     bpp;
	int     size_line;
	int     endian;
}   t_texture;

typedef struct s_counter
{
	int     count_no;
	int     count_so;
	int     count_we;
	int     count_ea;
	int     count_f;
	int     count_c;

}   t_counter;

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
	char    **file_content;
	int     floor_color[3];
	int     ceiling_color[3];
	int     map_start_index;
	char    **map;
	int     width;
	int     height;
}   t_map;


typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_texture	screen;
	t_texture	north_texture;
	t_texture	south_texture;
	t_texture	west_texture;
	t_texture	east_texture;
	t_map		map;
	t_counter	counter;
	t_player	player;
}	t_data;

#endif