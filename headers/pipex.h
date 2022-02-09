/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:19:10 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/09 15:05:08 by vantonie         ###   ########.fr       */
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
	pid_t	pid_child1;
	pid_t	pid_child2;
}				t_pipex;

int	get_next_var(t_pipex *pipex);
void	pipex(t_pipex *pipex);

#endif
