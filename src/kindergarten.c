/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kindergarten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:22:24 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/10 15:27:37 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	child_one(t_pipex *pipex)
{
	pipex->first_cmd = malloc(1 * sizeof(t_execv));
	dup2(pipex->fd[1], 1);
	close(pipex->fd[0]);
	dup2(pipex->file_in, 0);
	pipex->first_cmd->argv = ft_split(pipex->s_argv[2], ' ');
	if(get_next_command(pipex, pipex->second_cmd) == 0)
		execve(pipex->first_cmd->path_cmd, pipex->first_cmd->argv, pipex->s_envp);
	else
		return;
}

void	child_two(t_pipex *pipex)
{
	pipex->second_cmd = malloc(1 * sizeof(t_execv));
	dup2(pipex->fd[0], 0);
	close(pipex->fd[1]);
	dup2(pipex->file_out, 1);
	pipex->second_cmd->argv = ft_split(pipex->s_argv[3], ' ');
	if(get_next_command(pipex, pipex->second_cmd) == 0)
		execve(pipex->second_cmd->path_cmd, pipex->second_cmd->argv, pipex->s_envp);
	else
		return;
}