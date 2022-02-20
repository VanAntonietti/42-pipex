/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:22:22 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/19 23:48:28 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	get_next_command(t_pipex *pipex, t_execv *cmdnow)
{
	char	*tmp;
	int		i;

	i = 0;
	while (pipex->path[i])
	{
		tmp = ft_strjoin(pipex->path[i], "/");
		cmdnow->path_cmd = ft_strjoin(tmp, cmdnow->argv[0]);
		free(tmp);
		if (access(cmdnow->path_cmd, X_OK) == 0)
			return (0);
		else
			free(cmdnow->path_cmd);
		i++;
	}
	return (1);
}

int	get_next_var(t_pipex *pipex)
{
	int		i;
	char	*path_local;

	i = 0;
	path_local = NULL;
	while (path_local == NULL)
	{
		path_local = ft_strnstr(pipex->s_envp[i], "PATH=", 5);
		if (pipex->s_envp[i] == NULL)
			return (1);
		i++;
	}
	path_local = ft_strchr(path_local, '/');
	pipex->path = ft_split(path_local, ':');
	return (0);
}

void	init_struct(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->s_argc = argc;
	pipex->s_argv = argv;
	pipex->s_envp = envp;
	pipex->err_num = 0;
	pipex->file_in = open(argv[1], O_RDONLY);
	pipex->file_out = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY);
	if (get_next_var(pipex) < 0)
		exit(1);
}
