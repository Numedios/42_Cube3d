/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:14:43 by zhamdouc          #+#    #+#             */
/*   Updated: 2023/04/26 19:21:09 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stddef.h>
# include "./../libs/printf/libftprintf.h"
# include "./../libs/gnl/get_next_line.h"
# include "./../libs/libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>

# define WHITE_SPACE "\t\n\v\f\r "//de 9 a 13 et le 32

typedef struct cube
{
	char **info;
	char **map;
	int start;
	int end;
	int len;
}				t_cube;

int		parsing(int argc, char *argv, t_cube *cube);
void	print_tab(char **tab);
void	free_tab(char **tab);
int		parsing_cube(int fd, t_cube *cube);
int		map_init(int fd, char *argv, t_cube *cube);

#endif
