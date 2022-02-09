/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:24:49 by vantonie          #+#    #+#             */
/*   Updated: 2021/09/17 01:32:06 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start < i)
	{
		j = 0;
		while (s[j] != '\0' && j < len)
		{
			j++;
		}
		len = j;
	}
	else
	{
		return (ft_strdup(""));
	}
	dst = ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, &s[start], len + 1);
	return (dst);
}
