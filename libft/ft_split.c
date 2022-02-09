/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:57:14 by vantonie          #+#    #+#             */
/*   Updated: 2021/09/17 01:32:06 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		while (s[i] == c && s[i] != 0)
		{
			i++;
		}
		while (s[i] != c && s[i] != 0)
		{
			i++;
		}
		if (s[i - 1] != c)
		{
			count++;
		}
	}
	return (count);
}

static	void	ft_fill(const char *s, char c, int len, char **res)
{
	int		count;
	int		len_word;
	char	*ss;

	count = 0;
	ss = (char *) s;
	while (count < len)
	{
		len_word = 0;
		while (*ss == c && *ss != 0)
		{
			ss++;
		}
		while (ss[len_word] != c && ss[len_word] != 0)
		{
			len_word++;
		}
		res[count] = ft_substr(ss, 0, len_word);
		count++;
		ss += len_word;
	}
	res[count] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		len;

	res = NULL;
	if (s == NULL)
	{
		return (NULL);
	}
	len = ft_count(s, c);
	res = (char **)malloc((len + 1) * sizeof(char *));
	if (!res)
	{
		return (NULL);
	}
	ft_fill(s, c, len, res);
	return (res);
}
