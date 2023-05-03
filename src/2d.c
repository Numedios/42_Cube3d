/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheylkoss <zheylkoss@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:08:43 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/05/03 18:48:51 by zheylkoss        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// void    setup(t_jett *jett)
// {
// 	// initialize all objects
// 	jett->height = 5;
// 	jett->width = 5;
// 	jett->moveSpeed = 3.0;
// 	jett->x = 0;//calcul la position de "N" ou un des 3 autres
// 	jett->y = 0;// same
// 	jett->walkDirection = 0;
// 	jett->turnDirection = 0;
// 	jett->rotationAngle = M_PI / 2;//a comprend
// 	jett->rotationSpeed = 3 * (M_PI / 180);
// }

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

void    minimap(void *mlx_ptr, void *win_ptr, t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;
	
	i = 0;
	j = 0;
	while (i < w_width)
	{
		while (j < w_height)
		{
			x = i / 32;
			y = j / 32;
			if (x < game->rows)
			{
				if (game->map[x][y] && (game->map[x][y] == '1' || game->map[x][y] == ' '))
					mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0x000000);
				else if (game->map[x][y] && game->map[x][y] == '0')
					mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0xFFFFFF);
				else if (game->map[x][y] && game->map[x][y] != '\n')
					mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0xFF0000);
			}
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (i < w_width)
	{
		while (j < w_height)
		{
			x = i / 32;
			if (x < game->rows)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0x000000);
			}
			j = j + 32;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (i < w_width)
	{
		while (j < w_height)
		{
			x = i / 32;
			if (x < game->rows)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0x000000);
			}
			j++;
		}
		j = 0;
		i = i + 32;
	}
}

void    draw(t_game *game)
{
	void    *mlx_ptr;
	void    *win_ptr;
	update();
	//render all objcts frame by frame
	/*Ce code ouvre une fenêtre graphique de 500x500 pixels avec le titre "Ma fenêtre".
	 La fonction mlx_loop() permet de démarrer la boucle d'événements pour que la fenêtre reste ouverte.*/
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, w_width, w_height, "cub3d");
	//floorandtop(mlx_ptr, win_ptr);
	minimap(mlx_ptr, win_ptr, game);
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFF0000);
	mlx_loop(mlx_ptr);
}
//peut etre devoir remplacer tous les espaces par des 1;
void    debut(t_game *game)
{
	int i;
	int j;
	t_jett	*jett;

	jett = malloc (sizeof (t_jett) * 1);
	// if (!jett)
	// 	return (NULL);
	// setup(jett);
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
	draw(game);
	
	
}