/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:08:43 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/05/02 17:29:51 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void    setup()
{
    // initialize all objects
}

void    update()
{
    // update all game objects we render the next frame
}


/*  cette fonction sert a avoir un sol et un ciel de base*/
void    floorandtop(void *mlx_ptr, void *win_ptr)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < 500)
    {
        while (j < 1000)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0x87CEEB);
            j++;
        }
        j = 0;
        i++;
    }
    while (i < 1000)
    {
        while (j < 1000)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0x7CFC00);
            j++;
        }
        j = 0;
        i++;
    }
}

void    draw()
{
    void    *mlx_ptr;
    void    *win_ptr;
    update();
    //render all objcts frame by frame
    /*Ce code ouvre une fenêtre graphique de 500x500 pixels avec le titre "Ma fenêtre".
     La fonction mlx_loop() permet de démarrer la boucle d'événements pour que la fenêtre reste ouverte.*/
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, w_width, w_height, "cub3d");
    floorandtop(mlx_ptr, win_ptr);
    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFF0000);
    mlx_loop(mlx_ptr);
}
//peut etre devoir remplacer tous les espaces par des 1;
void    debut(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (game->map[i])
    {
        while (game->map[i][j])
            j++;
        game->cols = j;
        j = 0;
        i++;
    }
    game->rows = i;
    draw();
    
    
}