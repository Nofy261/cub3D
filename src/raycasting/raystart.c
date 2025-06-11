/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raystart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:53:27 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 15:30:59 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int is_traversable(char c)
{
    return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

/*
 * Essaie de déplacer le joueur selon orient (en radians) en testant les collisions.
 */
static void handle_collision(t_data *data, double orient)
{
    double angle = atan2(data->player.dir_y, data->player.dir_x);
    double nx = data->player.pos_x + cos(angle + orient) * 0.1;
    double ny = data->player.pos_y + sin(angle + orient) * 0.1;

    if (is_traversable(data->map.map[(int)ny][(int)nx]))
    {
        data->player.pos_x = nx;
        data->player.pos_y = ny;
    }
}

/*
 * Callback clavier pour déplacements et rotations.
 */
static int key_mouv(int keycode, void *param)
{
    t_data *data = param;

    if (keycode == XK_W)
        handle_collision(data, 0);
    else if (keycode == XK_S)
        handle_collision(data, M_PI);
    else if (keycode == XK_A)
        handle_collision(data, -M_PI/2);
    else if (keycode == XK_D)
        handle_collision(data, M_PI/2);
    else if (keycode == XK_Left || keycode == XK_Right)
    {
        double rot = (keycode == XK_Left) ? -0.05 : 0.05;
        /* rotation du vecteur direction */
        double odx = data->player.dir_x;
        data->player.dir_x = odx * cos(rot) - data->player.dir_y * sin(rot);
        data->player.dir_y = odx * sin(rot) + data->player.dir_y * cos(rot);
        /* rotation du plan de projection */
        double opx = data->player.plane_x;
        data->player.plane_x = opx * cos(rot) - data->player.plane_y * sin(rot);
        data->player.plane_y = opx * sin(rot) + data->player.plane_y * cos(rot);
    }
    else if (keycode == XK_Escape)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);

    return (0);
}

/*
 * Démarre la fenêtre, crée l’image, l’affiche, hook clavier et loop MLX.
 */
void start_game(t_data *data)
{
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
        exit_error(data, "Failed to init MLX");

    data->win_ptr = mlx_new_window(data->mlx_ptr,
                                   WINDOWS_WIDTH,
                                   WINDOWS_HEIGHT,
                                   "cub3d");
    if (!data->win_ptr)
        exit_error(data, "Failed to create window");

    data->screen.img_ptr = mlx_new_image(data->mlx_ptr,
                                         WINDOWS_WIDTH,
                                         WINDOWS_HEIGHT);
    if (!data->screen.img_ptr)
        exit_error(data, "Failed to create image");

    data->screen.data = mlx_get_data_addr(data->screen.img_ptr,
                                          &data->screen.bpp,
                                          &data->screen.size_line,
                                          &data->screen.endian);

    mlx_put_image_to_window(data->mlx_ptr,
                            data->win_ptr,
                            data->screen.img_ptr,
                            0, 0);

    mlx_key_hook(data->win_ptr, key_mouv, data);
    mlx_loop(data->mlx_ptr);
}
