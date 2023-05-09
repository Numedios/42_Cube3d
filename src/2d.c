/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:08:43 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/05/09 18:35:38 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    setup(t_jett *jett, t_game *game)
{
	// initialize all objects
	jett->height = 1;
	jett->width = 1;
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
	// jett->angle = 90;
	jett->wall_width = 1;
	jett->nb_rays = w_width / jett->wall_width;
	jett->FOV_angle = 60 * (M_PI / 180); //60 correspond la taille de l'angle de vision
	jett->rotationAngle = M_PI / 2;//a comprend, (M_PI / 2 = 90)
	jett->rotationSpeed = 1 * (M_PI / 180);
	jett->ray_angle = jett->rotationAngle -(jett->FOV_angle / 2);//debut de l'angle  de vision qu'il faudra augmenter de FOV_angle/nb_rays
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
				else if (jett->map[x][y] && jett->map[x][y] == 'S')
					mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0xFF0000);
			}
			j++;
		}
		j = 0;
		i++;
	}
	// printf("valeur map :%c\n", jett->map[12][31/32]);
	// printf("valeur map :%c\n", jett->map[12][32/32]);
	// printf("valeur map :%c\n", jett->map[12][33/32]);
	// printf("valeur map :%c\n", jett->map[12][34/32]);
	// i = 0;
	// j = 0;
	// while (i < w_width)
	// {
	// 	while (j < w_height)
	// 	{
	// 		x = i / 32;
	// 		if (x < jett->rows)
	// 		{
	// 			mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0x000000);
	// 		}
	// 		j = j + 32;
	// 	}
	// 	j = 0;
	// 	i++;
	// }
	// i = 0;
	// j = 0;
	// while (i < w_width)
	// {
	// 	while (j < w_height)
	// 	{
	// 		x = i / 32;
	// 		if (x < jett->rows)
	// 		{
	// 			mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0x000000);
	// 		}
	// 		j++;
	// 	}
	// 	j = 0;
	// 	i = i + 32;
	// }
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
				while (len_1 < jett->height)
				{
					while (len_2 < jett->width)
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
	while (len_1 < jett->height)
	{
		while (len_2 < jett->width)
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
	while (len_1 < jett->height)
	{
		while (len_2 < jett->width)
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

/*
faire un check descrechendo
int check_wall(t_jett *jett, int x, int y)
{
	int i;
	int j;
	int x_old;
	int y_old;

	x_old = x;
	y_old = y;
	while (x != 0 || y != 0)
	{
		if (x_old == 4 && y_old == 0)
		{
			i = (jett->x + x + 4) / 32;
			j = (jett->y + y + 4) / 32;	
		}
		else if (x == 0 && y_old == 4)
		{
			i = (jett->x + x + 4) / 32;
			j = (jett->y + y + 4) / 32;
		}
		else
		{
			i = (jett->x + x) / 32;
			j = (jett->y + y) / 32;	
		}
		if (jett->map[i][j] && (jett->map[i][j] == '1' || jett->map[i][j] == ' '))
		{
			if (x != 0)
			{
				if (x > 0)
					x--;
				if (x < 0)
					x++;
			}
			else if (y != 0)
			{
				if (y > 0)
					y--;
				if (y < 0)
					y++;
			}
		}
		else
			break ;
	}
	if (jett->map[i][j] && (jett->map[i][j] == '1' || jett->map[i][j] == ' '))
		return (0);
	else if (x != 0)
		return (x);
	else if (y != 0)
		return (y);
	return (0);
}
*/

/*
HIT WALL	
delta y : long ystep (32);
delta x : xstep (32);
*/




int check_wall(t_jett *jett, float pos_x, float pos_y, double x, double y)//probleme d'arrondie qui cree un ecart d'un pixel
{
	int i;
	int j;
	
	// if (x == 1 && y == 0)
	// {
	// 	i = (jett->x + x + 1) / 32;
	// 	j = (jett->y + y + 1) / 32;	
	// }
	// else if (x == 0 && y == 1)
	// {
	// 	i = (jett->x + x + 1) / 32;
	// 	j = (jett->y + y + 1) / 32;
	// }
	// else
	// {
	if (x > 0)
		x = 1;
	if (x < 0)
		x = -1;
	if (y > 0)
		y = 1;
	if (y < 0)
		y = -1;
	i = (pos_x + x) / 32;
	j = (pos_y + y) / 32;	
	// }
	// printf("valeur i :%d\n", i);
	// printf("valeur j :%d\n", j);
	// printf("valeur x :%f\n", x);
	// printf("valeur y :%f\n", y);
	// printf("valeur pos_x :%f\n", pos_x);
	// printf("valeur pos_y :%f\n", pos_y);
	if (jett->map[i][j] && (jett->map[i][j] == '1' || jett->map[i][j] == ' '))
		return (0);
	else if (x != 0)
		return (x);
	else if (y != 0)
		return (y);
	return (0);
}

int check_wall_mov(t_jett *jett, double x, double y)
{
	int i;
	int j;
	
	// if (x == 1 && y == 0)
	// {
	// 	i = (jett->x + x + 1) / 32;
	// 	j = (jett->y + y + 1) / 32;	
	// }
	// else if (x == 0 && y == 1)
	// {
	// 	i = (jett->x + x + 1) / 32;
	// 	j = (jett->y + y + 1) / 32;
	// }
	// else
	// {
	if (x > 0)
		x = 1;
	if (x < 0)
		x = -1;
	if (y > 0)
		y = 1;
	if (y < 0)
		y = -1;
	i = (jett->x + x) / 32;
	j = (jett->y + y) / 32;	
	// }
	// printf("valeur i :%d\n", i);
	// printf("valeur j :%d\n", j);
	// printf("valeur x :%f\n", x);
	// printf("valeur y :%f\n", y);
	if (jett->map[i][j] && (jett->map[i][j] == '1' || jett->map[i][j] == ' '))
		return (0);
	else if (x != 0)
		return (x);
	else if (y != 0)
		return (y);
	return (0);
}

void	del_ray(t_jett *jett)
{
	int i;
	int j;
	double angle;
	float x;
	float y;
	int count;

	count = 0;
	i = 0;
	j = 0;
	//angle = jett->rotationAngle * (180 / M_PI);
	angle = jett->rotationAngle - (20 * (M_PI / 180));
	x = jett->old_x;
	y = jett->old_y;
	//quand rotation-> angle sera egale a 0 et quon fait moins un on passe a 359 et inversement
	while (count < 40)
	{
		while (i < 20)//la taille dependra de quand il heurte un mur 
		{	
			/*
			detecter si ou je suis est un 1 ou 0
			avec l'angle qu'on connait calculer pour chaque intersection horizontale et verticale quand aura lieu l'intersection la plus proche
			*/
			if (check_wall(jett, x, y, (sin(angle) * -1), 0) != 0 && check_wall(jett, x, y, 0, (cos(angle) * -1)) != 0)
			{
				mlx_pixel_put(jett->mlx_ptr, jett->win_ptr, y , x, 0xFFFFFF);
				x = x + sin(angle) * -1;
				y = y + cos(angle) * -1;
			}
			else
				break ; 
			i++; 
		}
		i = 0;
		x = jett->old_x;
		y = jett->old_y;
		count++;
		angle += (1 * (M_PI / 180));
	}
}

void	print_ray(t_jett *jett)
{
	int i;
	int j;
	double angle;
	float x;
	float y;
	int count;
	
	i = 0;
	j = 0;
	count = 0;
	angle = jett->rotationAngle - (20 * (M_PI / 180));
	//angle = jett->rotationAngle * (180 / M_PI);
	//quand rotation-> angle sera egale a 0 et quon fait moins un on passe a 359 et inversement
	x = jett->x;
	y = jett->y;
	while (count < 40)
	{
		while (i < 20)//la taille dependra de quand il heurte un mur 
		{
			// if (angle <= 180 && angle >= 0)
			// {
			// 	printf("hello\n");
				// j = i * -1;
				if (check_wall(jett, x, y, (sin(angle) * -1), 0) != 0 && check_wall(jett, x , y, 0, (cos(angle) * -1)) != 0)
				{
					mlx_pixel_put(jett->mlx_ptr, jett->win_ptr, y, x, 0x0000FF);
					x = x + sin(angle) * -1;
					y = y + cos(angle) * -1;
				}
				else//ici il faudra enregistrer la distance du rayon
					break ;
			// }
			// else
			// {
			// 	printf("salut\n");
			// 	j = i * 1;
			// 	mlx_pixel_put(jett->mlx_ptr, jett->win_ptr, jett->y + cos(jett->rotationAngle) * i ,jett->x + sin(jett->rotationAngle) * j, 0x0000FF);
			// }
			// j = i; 
			i++; 
		}
		i = 0;
		x = jett->x;
		y = jett->y;
		count++;
		angle += (1 * (M_PI / 180));
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
		del_ray(jett);
		jett->walkDirection--;
		if (check_wall_mov(jett, (sin(jett->rotationAngle) * -1), 0) != 0 && check_wall_mov(jett, 0, (cos(jett->rotationAngle) * -1)) != 0)
		{
			jett->x = jett->x + sin(jett->rotationAngle) * -1;
			jett->y = jett->y + cos(jett->rotationAngle) * -1;
		}
		print_ray(jett);
		jett->walkDirection = 0;
       // jett->x = jett->x + check_wall(jett, -1, 0);
	}
	if (key == 97) //A, doit deplacer la camera
	{
		del_ray(jett);
		jett->turnDirection--;
		jett->rotationAngle += jett->rotationSpeed * jett->turnDirection;
		print_ray(jett);
		jett->turnDirection = 0;
        //jett->y = jett->y + check_wall(jett, 0, -1);
	}
	if (key == 115) // S
	{
		del_ray(jett);
		jett->walkDirection++;
		if (check_wall_mov(jett, (sin(jett->rotationAngle) * 1), 0) != 0 && check_wall_mov(jett, 0, (cos(jett->rotationAngle) * 1)) != 0)
		{
			jett->y = jett->y - cos(jett->rotationAngle) * -1;
			jett->x = jett->x - sin(jett->rotationAngle) * -1;
		}
		print_ray(jett);
		jett->walkDirection = 0;
		//jett->x = jett-> x + check_wall(jett, 1, 0);
	}
	if (key == 100) // D, doit deplacer la camera
	{
		del_ray(jett);
		jett->turnDirection++;
		jett->rotationAngle += jett->rotationSpeed * jett->turnDirection;
		print_ray(jett);
		jett->turnDirection = 0;
		//jett->y = jett->y + check_wall(jett, 0, 1);
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
	// void    *mlx_ptr;	jett->map = game->map;

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
	print_ray(jett);
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
	return (NULL);
}