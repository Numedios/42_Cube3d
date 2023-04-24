/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:16:08 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/04/24 18:03:43 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_end(t_cube *cube)
{
	if (cube->map)
		free_tab(cube->map);
	if (cube->info)
		free_tab(cube->info);
	if (cube)
		free(cube);
}

int	main(int argc, char **argv)
{
	t_cube	*cube;
	
	cube = malloc (sizeof (t_cube));
	if (!cube)
		return (1);
	if (parsing(argc, argv[1], cube) == 1)
	{
		ft_end(cube);
		return (1);
	}
	ft_end(cube);
	return (0);
}

