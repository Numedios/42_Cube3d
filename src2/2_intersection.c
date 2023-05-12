/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_intersection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:32:50 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/05/12 18:27:32 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	print_this_limit(t_jett *jett, float next_x, float next_y)
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
// 	while (x != next_x && y !=)
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

// void draw_line(int x1, int y1, int x2, int y2, t_jett *jett)
// {
//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx = x1 < x2 ? 1 : -1;
//     int sy = y1 < y2 ? 1 : -1;
//     int err = dx - dy;
    
//     while (x1 != x2 || y1 != y2) {
//         mlx_pixel_put(jett->mlx_ptr, jett->win_ptr, y1, x1,  0x000000FF);
//         int e2 = 2 * err;
//         if (e2 > -dy) {
//             err -= dy;
//             x1 += sx;
//         }
//         if (e2 < dx) {
//             err += dx;
//             y1 += sy;
//         }
//     }
// }

//faire une fonction qui incremente l'angle
// void angleplus(t_jett *jett, float anglemove)
// {
//     float angle = jett->rotationAngle * (180.0 / M_PI);
//     angle = fmod(angle + anglemove, 360.0);
//     if (angle < 0)
//         angle += 360.0;
//     jett->rotationAngle = angle * (M_PI / 180.0);
// }


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
int wall_hit_horizontal(t_jett *jett, float angle)//il faut deplacer x pour ca 
{
    float x;
    float y;
    int next_x;
    int next_y;
    float delta_x;
    float delta_y;
    int i;
    int j;
    
    x = jett->x;
    y = jett->y;
    printf("valeur de y = %f\n", y);
    printf("valeur de x = %f\n", x);
   // angle = angle * (180 / M_PI);
    //soit faire avec cos et sin, soit faire 4 cas avec les angles : de 0 a 90, 90 a 180, 180 a 270 et 270 a 360
    if (sin(angle) < 0 && sin(angle) >= -1)
    {
        next_y = ((y / 64) * 64); 
        printf("valeur de Ay = %d\n", next_y);
        printf("valeur de angle = %f\n", angle * (180 / M_PI));
        delta_y = -64;
    }
    else
    {
        next_y = (((y / 64) + 1) * 64);
        delta_y = 64;
    }
    next_x = x + ((next_y - y) / tan(angle));
    delta_x = 64 / tan(angle);
    if (cos(angle) < 0 && cos(angle) >= -1)
    {
        //printf("angle valeur : %f \n", angle * (180 / M_PI));
        if ( delta_x < 0)
            delta_x = -delta_x;
        else
            delta_x = delta_x;
        
    }
        //next_x = x +((next_x - y) / tan(angle));
    else
    {
        if (delta_x > 0)
            delta_x = -delta_x;
        else
            delta_x = delta_x;
    }
        //next_x = x - ((y - next_y) / tan(angle));
    /*
    next_y = (y / 64) * 64; //le fait que next_y soit un int, permettre de faire un arrondi vers le bas mais je doiten fair un vers le haut 
    next_x = x + ((y - next_y)/ tan(angle));//vers la gauche on diminue de delta x et si on va vers la droite on ugmente de delta x
    
    delta_y = 64;// vers le haut on diminue de 64, vers le bas on augmente de 64
    delta_x = delta_y / tan(angle);
    */
    while (1)
    {
        i = next_x / 64;
        j = next_y / 64;
        if (jett->map[i][j] && jett->map[i][j] != '1' && jett->map[i][j] != ' ')
        {
            next_x = next_x + delta_x;
            next_y = next_y + delta_y;
        }
        else
            break;
    }
    //next_x et next_y sont egaux a la premiere rencontre d'un mur horizontle
    //print_this_limit(jett, float_x, float_y);
    draw_line(jett->x, jett->y, next_x, next_y, jett);
}

/*      vertical hit     */

int wall_hit_vertical(t_jett *jett)//il faut deplacer x pour ca 
{
    float x;
    float y;
    int next_x;
    int next_y;
    int delta_x;
    int delta_y;
    int i;
    int j;
    
    x = jett->x;
    y = jett->y;
    //soit faire avec cos et sin, soit faire 4 cas avec les angles : de 0 a 90, 90 a 180, 180 a 270 et 270 a 360

    if (cos(jett->rotationAngle) >= 0 && cos(jett->rotationAngle <= 1))
    {
        next_x = ((y / 64) * 64) + 64;
        delta_x = 64;
    }
    else
    {
        next_x = (y / 64) * 64; 
        delta_x = -64;
    }
    next_y = y +((next_x - x) * tan(jett->rotationAngle));
    if (sin(jett->rotationAngle) >= 0 && sin(jett->rotationAngle <= 1))
        delta_y = (delta_x * tan(jett->rotationAngle)) * -1;
        //next_x = x +((next_x - y) / tan(jett->rotationAngle));
    else
        delta_y = delta_x * tan(jett->rotationAngle);
        //next_x = x - ((y - next_y) / tan(jett->rotationAngle));
    /*
    next_y = (y / 64) * 64; //le fait que next_y soit un int, permettre de faire un arrondi vers le bas mais je doiten fair un vers le haut 
    next_x = x + ((y - next_y)/ tan(jett->rotationAngle));//vers la gauche on diminue de delta x et si on va vers la droite on ugmente de delta x
    
    delta_y = 64;// vers le haut on diminue de 64, vers le bas on augmente de 64
    delta_x = delta_y / tan(jett->rotationAngle);
    */
    while (1)
    {
        i = next_x / 64;
        j = next_y / 64;
        if (jett->map[i][j] != '1' && jett->map[i][j] != ' ')
        {
            next_x = next_x + delta_x;
            next_y = next_y + delta_y;
        }
        else
            break;
    }
    //next_x et next_y sont egaux a la premiere rencontre d'un mur horizontle
}