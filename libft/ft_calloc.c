/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:39:55 by vantonie          #+#    #+#             */
/*   Updated: 2021/11/13 17:39:27 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t m)
{
	void	*p;
	void	*d;

	p = malloc(n * m);
	if (p == 0)
	{
		return (p);
	}
	ft_bzero(p, n * m);
	d = p;
	free(p);
	return (d);
}
