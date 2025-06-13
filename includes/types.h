/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:09:53 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 09:21:59 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "cub3d.h"


typedef struct s_texture
{
    
    mlx_texture_t   *north_texture;
    mlx_texture_t   *south_texture;
    mlx_texture_t   *west_texture;
    mlx_texture_t   *east_texture;    
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
    float   player_pos_x;
    float   player_pos_y;
    float   angle;//angle vers lequel le joueur regarde
    float   fov; // champ de vision       
}   t_player;


typedef struct s_map
{
    char    **file_content;
    int     floor_color[3];
    int     ceiling_color[3];
    int     map_start_index;
    char    **map;
    int     width; // largeur
    int     height; // hauteur
    
    
}   t_map;


typedef struct s_data
{
    mlx_image_t		    *image;
    mlx_t				*mlx;
    t_map               *map;
    t_texture           *texture;
    t_counter           *counter;
    t_player            *player;
    
}   t_data;





#endif