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

/*      horizontal hit     */
//savoir si l'angle se dirige vers le haut gauche ou haut droit ou bas gauche ou bas droit
int wall_hit_horizontal(t_jett *jett)//il faut deplacer x pour ca 
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
    first_y = (y / 32) * 32; //le fait que first_y soit un int, permettre de faire un arrondi vers le bas mais je doiten fair un vers le haut 
    first_x = x + ((y - first_y)/ tan(jett->rotationAngle));//vers la gauche on diminue de delta x et si on va vers la droite on ugmente de delta x
    
    delta_y = 32;// vers le haut on diminue de 32, vers le bas on augmente de 32
    delta_x = delta_y / tan(jett->rotationAngle);
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














/*      vertical hit     */