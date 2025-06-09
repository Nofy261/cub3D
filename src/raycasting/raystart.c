/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raystart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:53:27 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/09 15:16:55 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// determiner la position du joueur
// determiner ou le joueur regarde
// lancer des rayons dans tous le champ de vision (FOV) du J:
// -si un rayon touche un mur : calcule la distance entre le mur touché et le joueur
// -plus la distance est petite (mur proche) plus la hauteur du mur a dessiner est grande
// -plus la distance est grande(mur loin) plus la hauteur du mur a dessiner est petite
// -faire pareil pour chaque rayon envoyé == image 3D 
// (Ex: 64colonnes de pixel(largeur) = 64 rayons a lancer)


static int	is_traversable(char c)
{
	if (c == '0' || c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

//on simule le deplacement et si c'est possible on fait le vrai deplacement ensuite
static void colision(t_data *data, float orientation)
{
    float new_pos_x;
    float new_pos_y;

    new_pos_x = data->player->player_pos_x + cos(data->player->angle + orientation) * 0.1;
    new_pos_y = data->player->player_pos_y + sin(data->player->angle + orientation) * 0.1;
    if (is_traversable(data->map->map[(int)new_pos_y][(int)new_pos_x]))
    {
        data->player->player_pos_x += cos(data->player->angle + orientation) * 0.05;
        data->player->player_pos_y += sin(data->player->angle + orientation) * 0.05;
    }  
}

float	normalize_angle(float num, float min, float max)
{
	if (num < min)
		return (max + num);
	if (num > max)
		return (num - max);
	return (num);
}

// float normalize_angle(float num, float min, float max) // a comparer resultat
// {
//     float range = max - min;
//     while (num < min)
//         num += range;
//     while (num > max)
//         num -= range;
//     return num;
// }


static void	key_mouv(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_A)
		colision(data, -1 * (M_PI / 2));
	if (keydata.key == MLX_KEY_D)
		colision(data, (M_PI / 2));
	if (keydata.key == MLX_KEY_W)
		colision(data, 0);
	if (keydata.key == MLX_KEY_S)
		colision(data, M_PI);
	if (keydata.key == MLX_KEY_LEFT)
		data->player->angle = normalize_angle(data->player->angle - 0.05, 0, M_PI * 2.0);
	if (keydata.key == MLX_KEY_RIGHT)
		data->player->angle = normalize_angle(data->player->angle + 0.05, 0, M_PI * 2.0);
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
}


void start_game(t_data *data)
{
    data->mlx = mlx_init(WINDOWS_WIDTH, WINDOWS_HEIGHT, "cub3d", false);
	if (!data->mlx)
		exit_error_with_array(data, NULL, "MLX initialization failed");
    data->image = mlx_new_image(data->mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT);
    if (!data->image)
        exit_error_with_array(data, NULL, "Failed to create image");
    if (mlx_image_to_window(data->mlx, data->image, 0, 0) < 0)
        exit_error_with_array(data, NULL, "Image couln't be displayed");
    mlx_key_hook(data->mlx, key_mouv, (void *)data);
	// mlx_loop_hook(data->mlx, raycast, (void *)data);
	// mlx_loop(data->mlx);
}






