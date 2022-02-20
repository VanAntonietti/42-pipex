/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantonie <vantonie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:19:10 by vantonie          #+#    #+#             */
/*   Updated: 2022/02/20 02:40:07 by vantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define DEC "0123456789"
# define HEX "0123456789ABCDEF"
# define HEX_L "0123456789abcdef"

typedef struct s_list
{
	void					*content;
	struct s_list			*next;
}							t_list;

typedef struct s_len{
	int	len;
	int	i;
}			t_len;

typedef enum e_bool {TRUE = 1, FALSE = 0}	t_bool;

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
	t_execv	*first_cmd;
	t_execv	*second_cmd;
}				t_pipex;

int		get_next_var(t_pipex *pipex);
void	pipex_init(t_pipex *pipex);
void	pipex_terminate(t_pipex *pipex);
int		get_next_command(t_pipex *pipex, t_execv *cmdnow);
int		get_next_var(t_pipex *pipex);
void	child_one(t_pipex *pipex);
void	child_two(t_pipex *pipex);
void	init_struct(t_pipex *pipex, int argc, char **argv, char **envp);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int n);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *str, const char *ptr, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
char	**ft_split_cmds(char const *s);
void	free_ptr(void **fread);

#endif
