/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheylkoss <zheylkoss@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:08:43 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/05/03 22:35:18 by zheylkoss        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    setup(t_jett *jett, t_game *game)
{
	// initialize all objects
	jett->height = 10;
	jett->width = 10;
	jett->moveSpeed = 3.0;
	jett->x = 0;//calcul la position de "N" ou un des 3 autres
	jett->y = 0;// same
	jett->old_x = 0;//calcul la position de "N" ou un des 3 autres
	jett->old_y = 0;// same
	jett->walkDirection = 0;
	jett->turnDirection = 0;
	jett->map = game->map;
	jett->cols = game->cols;
	jett->rows = game->rows; 
	//jett->rotationAngle = M_PI / 2;//a comprend
	//jett->rotationSpeed = 3 * (M_PI / 180);
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

void    minimap(void *mlx_ptr, void *win_ptr, t_jett *jett)
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
			if (x < jett->rows)
			{
				if (jett->map[x][y] && (jett->map[x][y] == '1' || jett->map[x][y] == ' '))
					mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0x000000);
				else if (jett->map[x][y] && jett->map[x][y] == '0')
					mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0xFFFFFF);
				else if (jett->map[x][y] && jett->map[x][y] != '\n')
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
			if (x < jett->rows)
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
			if (x < jett->rows)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0x000000);
			}
			j++;
		}
		j = 0;
		i = i + 32;
	}
}

void spawn_jett(void *mlx_ptr, void *win_ptr, t_jett *jett, t_game *game)
{
	int i;
	int j;
	int x;
	int y;
	int len_1;
	int len_2;
	
	i = 0;
	j = 0;
	len_1 = 0;
	len_2 = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'S')// mettre les autres directions
			{
				jett->x = i * 32;
				jett->y = j * 32;
				x = jett->x;
				y = jett->y;
				while (len_1 < 10)
				{
					while (len_2 < 10)
					{
						mlx_pixel_put(mlx_ptr, win_ptr, y, x, 0x0000FF);
						y++;
						len_2++;
					}
					y = jett->y;
					x++;
					len_2 = 0;
					len_1++;
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void update_jett(t_jett *jett)
{
	int x;
	int y;
	int len_1;
	int len_2;
	
	len_1 = 0;
	len_2 = 0;
	x = jett->x;
	y = jett->y;
	while (len_1 < 10)
	{
		while (len_2 < 10)
		{
			mlx_pixel_put(jett->mlx_ptr, jett->win_ptr, y, x, 0x0000FF);
			y++;
			len_2++;
		}
		y = jett->y;
		x++;
		len_2 = 0;
		len_1++;
	}
}

void del_jett(t_jett *jett)
{
	int x;
	int y;
	int len_1;
	int len_2;
	
	len_1 = 0;
	len_2 = 0;
	x = jett->old_x;
	y = jett->old_y;
	while (len_1 < 10)
	{
		while (len_2 < 10)
		{
			mlx_pixel_put(jett->mlx_ptr, jett->win_ptr, y, x, 0xFFFFFF);
			y++;
			len_2++;
		}
		y = jett->old_y;
		x++;
		len_2 = 0;
		len_1++;
	}
}

int deal_key(int key, t_jett *jett)
{
	jett->old_x = jett->x;
	jett->old_y = jett->y;
    if (key == 65307) // 53 est le code de la touche "esc"
	{
        mlx_loop_end(jett->mlx_ptr);
	}
	if (key == 119) // W
	{
        jett->x = jett->x - 5;
	}
	if (key == 97) //A
	{
        jett->y = jett->y - 5;
	}
	if (key == 115) // S
	{
		jett->x = jett-> x + 5;
	}
	if (key == 100) // D
	{
		jett->y = jett->y + 5;
	}
	//mlx_clear_window(jett->mlx_ptr, jett->win_ptr);//ou supp ancienne position de jett et ensuite mettre la nouvelle
	//mettre les colision
	//minimap(jett->mlx_ptr, jett->win_ptr, jett);
	del_jett(jett);
	update_jett(jett);
    return (0);
}

void    draw(t_game *game, t_jett *jett)
{
	// void    *mlx_ptr;
	// void    *win_ptr;
	update();
	//render all objcts frame by frame
	/*Ce code ouvre une fenêtre graphique de 500x500 pixels avec le titre "Ma fenêtre".
	 La fonction mlx_loop() permet de démarrer la boucle d'événements pour que la fenêtre reste ouverte.*/
	jett->mlx_ptr = mlx_init();
	jett->win_ptr = mlx_new_window(jett->mlx_ptr, w_width, w_height, "cub3d");
	//floorandtop(mlx_ptr, win_ptr);
	minimap(jett->mlx_ptr, jett->win_ptr, jett);
	spawn_jett(jett->mlx_ptr, jett->win_ptr, jett, game);
	mlx_key_hook(jett->win_ptr, deal_key, jett); // 2 est le code de l'événement de pression de touche
	mlx_hook(jett->win_ptr,2, 1L<<0, deal_key, jett);
	//mlx_loop_hook(jett->mlx_ptr,)
	mlx_loop(jett->mlx_ptr);
	//minimap(jett->mlx_ptr, jett->win_ptr, jett);

	mlx_destroy_window(jett->mlx_ptr, jett->win_ptr);
    mlx_destroy_display(jett->mlx_ptr);
    free(jett);
}
//peut etre devoir remplacer tous les espaces par des 1;
void    *debut(t_game *game)
{
	int i;
	int j;
	t_jett	*jett;

	jett = malloc (sizeof (t_jett) * 1);
	if (!jett)
		return (NULL);
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
	setup(jett, game);
	draw(game, jett);
	
	
}