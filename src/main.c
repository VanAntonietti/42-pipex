/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:10:38 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/09 17:31:20 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include <stdio.h>

// static int	execute_cmds(t_pipex *pipex, int *fd, int i)
// {
// 	pid_t pid;

// 	pid = fork();
// 	if (pid == -1)
// 		exit(1);
// 	else if(pid == 0)
// 	{
		
// 	}	
// }

// void	pipex(t_pipex *pipex)
// {
// 	int	i;
// 	int	p[2];

// 	i = 0;
// 	while(i < pipex->s_argc - 3)
// 	{
// 		if(pipe(p) == -1)
// 			exit(1);
// 		if(execute_cmds(pipex, p, i) == -1)
// 			exit(1);
// 		i++;	
// 	}
// }
int	get_next_command(t_pipex *pipex, t_execv *cmdnow)
{
	char	*tmp;
	int		i;
	
	i = 0;
	while(pipex->path[i])
	{
		tmp = ft_strjoin(pipex->path[i], "/");
		cmdnow->path_cmd = ft_strjoin(tmp, cmdnow->argv[0]);
		free(tmp);
		if(access(cmdnow->path_cmd, X_OK) == 0)
			return(0);
	i++;
	}
	return(1);
}

void child_one(t_pipex *pipex)
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

void	pipex_init(t_pipex *pipex)
{
	if(pipe(pipex->fd) < 0)
		exit(1);
	child_one(pipex);
	pipex->pid_child1 = fork();
	if(pipex->pid_child1 < 0)
		exit(1);
	if(pipex->pid_child2 < 0)
		exit(1);
	if(pipex->pid_child1 == 0)
		child_one(pipex);
	if(pipex->pid_child2 == 0)
		child_two(pipex);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	// waitpid(pipex->pid_child1, NULL, 0);
	// waitpid(pipex->pid_child2, NULL, 0);
}

int	get_next_var(t_pipex *pipex)
{
	int		i;
	char	*path_local;
	
	i = 0;
	path_local = NULL;
	while(path_local == NULL)
	{
		path_local = ft_strnstr(pipex->s_envp[i], "PATH=", 5);
		if(pipex->s_envp[i] == NULL)
			return(1);
		i++;
	}
	path_local = ft_strchr(path_local, '/');
	pipex->path = ft_split(path_local, ':');
	printf("%s \n", path_local);
	printf("%s \n", pipex->path[0]);
	printf("%s \n", pipex->path[1]);
	printf("%s \n", pipex->path[2]);
	printf("%s \n", pipex->path[3]);
	printf("%s \n", pipex->path[4]);
	
	return(0);
}

// void	pipex_terminate(t_pipex *pipex)
// {
	
// }

int main(int argc, char **argv, char **envp)
{
	t_pipex *pipex;
	pipex = malloc(1 * sizeof(t_pipex));

	pipex->s_argc = argc;
	pipex->s_argv = argv;
	pipex->s_envp = envp;

	if (argc != 5)
		return(1);
	pipex->file_in = open(argv[1], O_RDONLY);
	pipex->file_out = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY);
	if(get_next_var(pipex) < 0)
		return(1);
	pipex_init(pipex);
	// pipex_terminate(&pipex);
	
	return(0);
}
