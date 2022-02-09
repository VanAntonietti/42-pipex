/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:10:38 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/07 15:10:36 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	get_next_var(t_pipex *pipex);
{
	int		i;
	char	*path_local;
	
	i = 0;
	while(path_local == NULL)
	{
		path_local = ft_strnstr(pipex->s_envp[i], "PATH=", 5);
		if (path_local == NULL)
			return(1);
		i++;
	}
	return(0);
}

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;

	pipex.s_argc = argc;
	pipex.s_argv = argv;
	pipex.s_envp = envp;

	if (argc != 5)
		return(1);

	pipex.file_in = open(argv[1], O_RDONLY);
	if(get_next_var(&pipex) == 1)
		return (1);
	pipex.file_out = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY);
	
	return(0);
}
