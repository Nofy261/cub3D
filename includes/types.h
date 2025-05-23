/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:09:53 by nolecler          #+#    #+#             */
/*   Updated: 2025/05/23 09:41:48 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "cub3d.h"


typedef struct s_texture
{
    mlx_texture_t *north_texture;
    mlx_texture_t *south_texture;
    mlx_texture_t *west_texture;
    mlx_texture_t *east_texture;


    
}   t_texture;


typedef struct s_map
{
    char    **file_content;// recuperer avec la fonction get_file_content?
    int     floor_color[3];
    int     ceiling_color[3];
    //char **map;
    //int width;
    //int height;
    
}   t_map;


typedef struct s_data
{
    mlx_t				*mlx;
    t_map               *map;
    t_texture           *texture;
    
}   t_data;





#endif