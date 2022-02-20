/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:10:38 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/20 13:23:43 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		write(1, "Error:\n\tFive arguments needed.\n", 31);
		return (1);
	}	
	init_struct (&pipex, argc, argv, envp);
	if(pipex_init (&pipex) == 1)
	{	
		write(1, "Error:\n\tPipe or fork error.\n", 28);
		pipex_terminate(&pipex);
		return (1);
	}
	pipex_terminate (&pipex);
	return (0);
}
