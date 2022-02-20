/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kindergarten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:22:24 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/20 03:20:29 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static void	command_not_found(char *cmd)
{
	while (*cmd != 0)
	{
		write(1, cmd, 1);
		cmd++;
	}
	write(1, ": command not found\n", 20);
}

void	child_one(t_pipex *pipex)
{
	dup2(pipex->fd[1], 1);
	close(pipex->fd[0]);
	dup2(pipex->file_in, 0);
	if (get_next_command(pipex, pipex->first_cmd) == 0)
		execve(pipex->first_cmd->path_cmd, pipex->first_cmd->argv,
			pipex->s_envp);
	else
	{
		command_not_found(pipex->first_cmd->argv[0]);
		exit(1);
	}	
}

void	child_two(t_pipex *pipex)
{
	dup2(pipex->fd[0], 0);
	close(pipex->fd[1]);
	dup2(pipex->file_out, 1);
	if (get_next_command(pipex, pipex->second_cmd) == 0)
		execve(pipex->second_cmd->path_cmd, pipex->second_cmd->argv,
			pipex->s_envp);
	else
	{
		command_not_found(pipex->second_cmd->argv[0]);
		exit(1);
	}
}	
