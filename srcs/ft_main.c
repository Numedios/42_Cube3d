/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:16:08 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/12/02 19:08:08 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int		child1(t_vare *vare, char **envp, int *pipe_fd, char **argv);
int		child2(t_vare *vare, char **envp, int *pipe_fd, char **argv);
void	free_all(t_vare *vare);
int		loop(t_vare *vare, char **envp, char **argv, pid_t pid);

int	main(int argc, char **argv, char **envp)
{
	t_vare	vare;
	pid_t	pid[2];
	int		n;

	init(&vare);
	n = 0;
	if (ft_check_open(argv, &vare, argc) != 0)
		return (free_all(&vare), 1);
	while (vare.i < 2)
	{
		pid[vare.i] = fork();
		if (pid[vare.i] < 0)
			return (write_error("fork_pid", &vare, "0011"), 1);
		if (loop(&vare, envp, argv, pid[vare.i]) != 0)
			break ;
		vare.i++;
	}
	close(vare.pipe_fd[1]);
	close(vare.pipe_fd[0]);
	waitpid(pid[0], &vare.status, 0);
	waitpid(pid[1], &vare.status, 0);
	free_all(&vare);
	return (0);
}

int	loop(t_vare *vare, char **envp, char **argv, pid_t pid)
{
	int	n;

	n = 0;
	if (vare->i == 0 && pid == 0)
	{
		n = child1(vare, envp, vare->pipe_fd, argv);
		if (n == 1)
			return (1);
	}
	if (vare->i == 1 && pid == 0)
	{
		n = child2(vare, envp, vare->pipe_fd, argv);
		if (n == 1)
			return (1);
	}
	return (0);
}
