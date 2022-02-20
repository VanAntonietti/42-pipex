/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:18:59 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/20 14:07:35 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	before_fork(t_pipex *pipex)
{
	pipex->first_cmd = malloc(1 * sizeof(struct s_execv));
	pipex->first_cmd->argv = ft_split_cmds(pipex->s_argv[2]);
	pipex->second_cmd = malloc(1 * sizeof(struct s_execv));
	pipex->second_cmd->argv = ft_split_cmds(pipex->s_argv[3]);
	pipex->first_cmd->path_cmd = NULL;
	pipex->second_cmd->path_cmd = NULL;
}

int	pipex_init(t_pipex *pipex)
{	
	pid_t	pid_child1;
	pid_t	pid_child2;

	pid_child1 = 0;
	pid_child2 = 0;
	if (pipe(pipex->fd) < 0)
		return (1);
	before_fork(pipex);
	pid_child1 = fork();
	if (pid_child1 < 0)
		return (1);
	if (pid_child1 == 0)
		child_one(pipex);
	pid_child2 = fork();
	if (pid_child2 < 0)
		return (1);
	if (pid_child2 == 0)
		child_two(pipex);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	waitpid(pid_child1, NULL, 0);
	waitpid(pid_child2, NULL, 0);
	return (0);
}

void	free_ptr(void **fread)
{
	if (*fread != NULL)
	{
		free(*fread);
		*fread = NULL;
	}
}

static void	final_terminate(t_pipex *pipex)
{
	free_ptr((void **)&pipex->first_cmd->argv);
	free_ptr((void **)&pipex->second_cmd->argv);
	free_ptr((void **)&pipex->first_cmd->path_cmd);
	free_ptr((void **)&pipex->second_cmd->path_cmd);
	free_ptr((void **)&pipex->first_cmd);
	free_ptr((void **)&pipex->second_cmd);
	free_ptr((void **)&pipex->path);
	close(pipex->file_in);
	close(pipex->file_out);
}	

void	pipex_terminate(t_pipex *pipex)
{	
	int	i;

	i = 0;
	while (pipex->path[i] != NULL)
	{
		free_ptr((void **)&pipex->path[i]);
		i++;
	}
	i = 0;
	while (pipex->first_cmd->argv[i] != NULL)
	{
		free_ptr((void **)&pipex->first_cmd->argv[i]);
		i++;
	}
	i = 0;
	while (pipex->second_cmd->argv[i] != NULL)
	{
		free_ptr((void **)&pipex->second_cmd->argv[i]);
		i++;
	}
	final_terminate(pipex);
}