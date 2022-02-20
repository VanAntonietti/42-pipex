/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kindergarten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:22:24 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/20 13:55:51 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	command_not_found(t_pipex *pipex)
{
	char	*tmp;

	if (pipex->err_num == 1)
		tmp = pipex->first_cmd->argv[0];
	else
		tmp = pipex->second_cmd->argv[0];
	while (tmp != 0)
	{
		write(1, tmp, 1);
		tmp++;
	}
	write(1, ": command not found\n", 20);
}

void	child_one(t_pipex *pipex)
{
	if (get_next_command(pipex, pipex->first_cmd) == 0)
	{
		dup2(pipex->fd[1], 1);
		close(pipex->fd[0]);
		dup2(pipex->file_in, 0);
		execve(pipex->first_cmd->path_cmd, pipex->first_cmd->argv,
			pipex->s_envp);
	}
	else
	{
		pipex->err_num = 1;
		command_not_found(pipex);
		exit(1);
	}
}

void	child_two(t_pipex *pipex)
{
	if (get_next_command(pipex, pipex->second_cmd) == 0)
	{
		dup2(pipex->fd[0], 0);
		close(pipex->fd[1]);
		dup2(pipex->file_out, 1);
		execve(pipex->second_cmd->path_cmd, pipex->second_cmd->argv,
			pipex->s_envp);
	}
	else
	{
		pipex->err_num = 2;
		command_not_found(pipex);
		exit(1);
	}
}
