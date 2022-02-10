/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:10:38 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/10 15:42:27 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;

	if (argc != 5)
		return(1);
	init_struct(&pipex, argc, argv, envp);
	pipex_init(&pipex);
	// pipex_terminate(&pipex);
	
	return(0);
}
