/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:44:58 by vantonie          #+#    #+#             */
/*   Updated: 2021/09/17 01:32:06 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		n1;
	int		n2;
	char	*s3;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	s3 = ft_calloc((n1 + n2 + 1), sizeof(char));
	if (s3 == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(s3, s1, n1 + 1);
	ft_strlcpy(&s3[n1], s2, n2 + 1);
	return (s3);
}
