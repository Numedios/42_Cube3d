/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_intersection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:32:50 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/05/10 15:06:51 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	print_this_limit(t_jett *jett, float first_x, float first_y)
// {
// 	int i;
// 	int j;
// 	double angle;
// 	float x;
// 	float y;
// 	int count;
	
// 	i = 0;
// 	j = 0;
// 	count = 0;
// 	angle = jett->rotationAngle - (20 * (M_PI / 180));
// 	//angle = jett->rotationAngle * (180 / M_PI);
// 	//quand rotation-> angle sera egale a 0 et quon fait moins un on passe a 359 et inversement
// 	x = jett->x;
// 	y = jett->y;
// 	while (x != first_x && y !=)
// 	{
// 		while (i < 20)//la taille dependra de quand il heurte un mur 
// 		{
// 			// if (angle <= 180 && angle >= 0)
// 			// {
// 			// 	printf("hello\n");
// 				// j = i * -1;
// 				if (check_wall(jett, x, y, (sin(angle) * -1), 0) != 0 && check_wall(jett, x , y, 0, (cos(angle) * 1)) != 0)
// 				{
// 					mlx_pixel_put(jett->mlx_ptr, jett->win_ptr, y, x, 0x0000FF);
// 					x = x + sin(angle) * -1;
// 					y = y + cos(angle) * 1;
// 				}
// 				else//ici il faudra enregistrer la distance du rayon
// 					break ;
// 			// }
// 			// else
// 			// {
// 			// 	printf("salut\n");
// 			// 	j = i * 1;
// 			// 	mlx_pixel_put(jett->mlx_ptr, jett->win_ptr, jett->y + cos(jett->rotationAngle) * i ,jett->x + sin(jett->rotationAngle) * j, 0x0000FF);
// 			// }
// 			// j = i; 
// 			i++; 
// 		}
// 		i = 0;
// 		x = jett->x;
// 		y = jett->y;
// 		count++;
// 		angle += (1 * (M_PI / 180));
// 	}
		
// }

void draw_line(int x1, int y1, int x2, int y2, t_jett *game)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, y1, x1,  0x000000FF);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

//faire une fonction qui incremente l'angle
void    angleplus(t_jett *jett, float anglemove)
{
    float   angle;

    angle = jett->rotationAngle * (180 / M_PI);
    angle = angle + anglemove; // si on augmente de 1, 
    if (angle > 360)
    {
        angle = angle - 360;
        jett->rotationAngle = angle * (M_PI / 180);
    }
    else if (angle < 0)
    {
        angle = 360 - (angle * -1);
        jett->rotationAngle = angle * (M_PI / 180);
    }
    else
        jett->rotationAngle = angle * (M_PI / 180);
}
/*      horizontal hit     */
//savoir si l'angle se dirige vers le haut gauche ou haut droit ou bas gauche ou bas droit
int wall_hit_horizontal(t_jett *jett)//il faut deplacer x pour ca 
{
    float x;
    float y;
    float first_x;
    float first_y;
    int delta_x;
    int delta_y;
    int i;
    int j;
    
    x = jett->x;
    y = jett->y;
    //soit faire avec cos et sin, soit faire 4 cas avec les angles : de 0 a 90, 90 a 180, 180 a 270 et 270 a 360

    if (sin(jett->rotationAngle) >= 0 && sin(jett->rotationAngle <= 1))
    {
        first_y = (y / 32) * 32; 
        delta_y = -32;
    }
    else
    {
        first_y = ((y / 32) * 32) + 32;
        delta_y = 32;
    }
    first_x = x +((first_y - y) / tan(jett->rotationAngle));
    if (cos(jett->rotationAngle) >= 0 && cos(jett->rotationAngle <= 1))
        delta_x = delta_y / tan(jett->rotationAngle);
        //first_x = x +((first_x - y) / tan(jett->rotationAngle));
    else
        delta_x = (delta_y / tan(jett->rotationAngle)) * -1;
        //first_x = x - ((y - first_y) / tan(jett->rotationAngle));
    /*
    first_y = (y / 32) * 32; //le fait que first_y soit un int, permettre de faire un arrondi vers le bas mais je doiten fair un vers le haut 
    first_x = x + ((y - first_y)/ tan(jett->rotationAngle));//vers la gauche on diminue de delta x et si on va vers la droite on ugmente de delta x
    
    delta_y = 32;// vers le haut on diminue de 32, vers le bas on augmente de 32
    delta_x = delta_y / tan(jett->rotationAngle);
    */
    while (1)
    {
        i = first_x / 32;
        j = first_y / 32;
        if (jett->map[i][j] != '1' && jett->map[i][j] != ' ')
        {
            first_x = first_x + delta_x;
            first_y = first_y + delta_y;
        }
        else
            break;
    }
    //first_x et first_y sont egaux a la premiere rencontre d'un mur horizontle
    //print_this_limit(jett, float_x, float_y);
    draw_line(jett->x, jett->y, first_x, first_y, jett);
}

/*      vertical hit     */

int wall_hit_vertical(t_jett *jett)//il faut deplacer x pour ca 
{
    float x;
    float y;
    int first_x;
    int first_y;
    int delta_x;
    int delta_y;
    int i;
    int j;
    
    x = jett->x;
    y = jett->y;
    //soit faire avec cos et sin, soit faire 4 cas avec les angles : de 0 a 90, 90 a 180, 180 a 270 et 270 a 360

    if (cos(jett->rotationAngle) >= 0 && cos(jett->rotationAngle <= 1))
    {
        first_x = ((y / 32) * 32) + 32;
        delta_x = 32;
    }
    else
    {
        first_x = (y / 32) * 32; 
        delta_x = -32;
    }
    first_y = y +((first_x - x) * tan(jett->rotationAngle));
    if (sin(jett->rotationAngle) >= 0 && sin(jett->rotationAngle <= 1))
        delta_y = (delta_x * tan(jett->rotationAngle)) * -1;
        //first_x = x +((first_x - y) / tan(jett->rotationAngle));
    else
        delta_y = delta_x * tan(jett->rotationAngle);
        //first_x = x - ((y - first_y) / tan(jett->rotationAngle));
    /*
    first_y = (y / 32) * 32; //le fait que first_y soit un int, permettre de faire un arrondi vers le bas mais je doiten fair un vers le haut 
    first_x = x + ((y - first_y)/ tan(jett->rotationAngle));//vers la gauche on diminue de delta x et si on va vers la droite on ugmente de delta x
    
    delta_y = 32;// vers le haut on diminue de 32, vers le bas on augmente de 32
    delta_x = delta_y / tan(jett->rotationAngle);
    */
    while (1)
    {
        i = first_x / 32;
        j = first_y / 32;
        if (jett->map[i][j] != '1' && jett->map[i][j] != ' ')
        {
            first_x = first_x + delta_x;
            first_y = first_y + delta_y;
        }
        else
            break;
    }
    //first_x et first_y sont egaux a la premiere rencontre d'un mur horizontle
}