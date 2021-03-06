/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitpipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:27:59 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/20 03:19:45 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static void		ft_fill_matrix(char const *s, size_t num, char **res);
static void		ft_remove_quotes(char **res, int num);
static size_t	count_s(char const *s);

char	**ft_split_cmds(char const *s)
{
	char	**res;
	size_t	num;

	res = NULL;
	if (!s)
		return (NULL);
	num = count_s(s);
	res = (char **)malloc(sizeof(char *) * (num + 1));
	if (!res)
		return (NULL);
	res[num] = NULL;
	ft_fill_matrix(s, num, res);
	ft_remove_quotes(res, num);
	return (res);
}

static void	ft_remove_quotes(char **res, int num)
{
	int		a;
	char	*tmp;

	a = -1;
	while (++a < num)
	{
		if (*res[a] == '\'' || *res[a] == '\"')
		{
			tmp = ft_substr(res[a], 1, ft_strlen(res[a]) - 2);
			free_ptr((void **)&res[a]);
			res[a] = tmp;
		}
	}
}

static int	verify_quotes(char const *s, size_t num)
{
	num++;
	while ((num == 1 || s[num] != 39) && s[num] != 0)
	{
		num++;
		if (s[num] == 39 && s[num + 1] == '\\')
			num++;
	}
	num++;
	return (num);
}

static size_t	count_s(char const *s)
{
	size_t		count;
	char		*tmp;

	tmp = (char *)s;
	count = 0;
	while (*tmp != 0)
	{
		while (*tmp == ' ' && *tmp != 0)
			++tmp;
		if (*(tmp) == 39)
		{
			tmp += verify_quotes(tmp, 0);
			if (*(tmp) == ' ' || *(tmp) == 0)
				count++;
		}
		else
		{
			while (*tmp != ' ' && *tmp != 0)
				++tmp;
			if (*(tmp - 1) != ' ')
				count++;
		}
	}
	return (count);
}

static void	ft_fill_matrix(char const *s, size_t num, char **res)
{
	size_t	count;
	char	*start_str;
	int		len_word;

	count = 0;
	start_str = (char *)s;
	while (count < num)
	{
		len_word = 0;
		while (*start_str == ' ' && *start_str != 0)
			++start_str;
		while (start_str[len_word] != ' ' && start_str[len_word] != 0)
		{
			if (start_str[len_word] == 39)
				len_word = verify_quotes(start_str, len_word);
			else if (start_str[len_word] == ' ' && start_str[len_word] == 0)
				break ;
			else
				len_word++;
		}
		res[count] = ft_substr(start_str, 0, len_word);
		start_str += len_word;
		count++;
	}
}
