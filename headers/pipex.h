/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:19:10 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/10 16:47:27 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

#include <stdio.h>

typedef struct s_execv
{
	char	*path_cmd;
	char	**argv;
}				t_execv;

typedef struct s_pipex
{
	int		file_in;
	int		file_out;
	int		s_argc;
	int		fd[2];
	char	**path;
	char	**s_argv;
	char	**s_envp;
	t_execv *first_cmd;
	t_execv	*second_cmd;
}				t_pipex;

int		get_next_var(t_pipex *pipex);
void	pipex_init(t_pipex *pipex);
void	pipex_terminate(t_pipex *pipex);
int		get_next_command(t_pipex *pipex, t_execv *cmdnow);
int		get_next_var(t_pipex *pipex);
void	child_one(t_pipex *pipex);
void	child_two(t_pipex *pipex);
void	init_struct(t_pipex *pipex, int argc, char **argv, char** envp);
#endif
