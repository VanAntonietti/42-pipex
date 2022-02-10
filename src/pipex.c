/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:18:59 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/10 15:45:02 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	pipex_init(t_pipex *pipex)
{	
	pid_t	pid_child1;
	pid_t	pid_child2;
	
	pid_child1 = 0;
	pid_child2 = 0;
	if(pipe(pipex->fd) < 0)
		exit(1);
	child_one(pipex);
	pid_child1 = fork();
	if(pid_child1 < 0)
		exit(1);
	if(pid_child2 < 0)
		exit(1);
	if(pid_child1 == 0)
		child_one(pipex);
	if(pid_child2 == 0)
		child_two(pipex);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	// waitpid(pipex->pid_child1, NULL, 0);
	// waitpid(pipex->pid_child2, NULL, 0);
}

// void	pipex_terminate(t_pipex *pipex)
// {
// 	return;
// }