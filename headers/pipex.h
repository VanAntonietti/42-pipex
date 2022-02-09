/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:19:10 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/07 15:10:21 by vantonie         ###   ########.fr       */
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

typedef struct s_pipex
{
	int	file_in;
	int file_out;
	int s_argc;
	char **path;
	char **s_argv;
	char **s_envp;
	
}				t_pipex;

int	get_next_var(t_pipex *pipex);

#endif
