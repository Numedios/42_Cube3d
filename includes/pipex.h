/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:14:43 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/12/02 19:46:51 by zhamdouc         ###   ########.fr       */
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

typedef struct s_vare
{
	char	*the_path;
	char	**cmd1;
	char	**cmd2;
	int		fd_in;
	int		fd_out;
	char	**cmd_path;
	char	*path;
	int		pipe_fd[2];
	int		i;
	int		status;
}				t_vare;
char	*get_the_path(char **envp, char **cmd, t_vare *vare);
void	free_all(t_vare *vare);
int		ft_check_open(char **argv, t_vare *vare, int argc);
int		end_close(t_vare *vare);
int		check_access(char **argv, t_vare *vare, int i);
void	free_all(t_vare *vare);
void	write_error(char *argv, t_vare *vare, char *tab);
void	write_error_2(char *argv, int i, t_vare *vare);
int		child1(t_vare *vare, char **envp, int *pipe_fd, char **argv);
int		child2(t_vare *vare, char **envp, int *pipe_fd, char **argv);
void	init(t_vare *vare);
int		check_space(char *argv);

#endif
