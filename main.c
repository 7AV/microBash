/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:49:28 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/02 16:28:16 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct	s_data
{
	char		**envp;
	char		**parced;
}				t_data;

void	ft_exe_fork()
{
	
}

int		ft_exe(t_data *data, char **todo, char **env)
{
	struct stat		stats;
	
	!(ft_strncmp(todo[0], "echo", 4)) ? ft_echo(todo) : 0; 				// +
	!(ft_strncmp(todo[0], "pwd", 3)) ? ft_pwd() : 0;					// +
	!(ft_strncmp(todo[0], "cd", 2)) ? ft_cd(todo, env) : 0;				// +-
	!(ft_strncmp(todo[0], "env", 3)) ? ft_env(todo, env) : 0;			// +
	!(ft_strncmp(todo[0], "export", 6)) ? ft_export(todo, &env) : 0;		//
	// !(ft_strncmp(todo[0], "unset", 5)) ? ft_unset(todo, env) : 0;		//
	// !(ft_strncmp(todo[0], "exit", 4)) ? ft_exit() : 0;					//

	// !(stat(todo[0], &stats)) ? ft_exe_fork(todo, env) : 0;
	
	int ind=0;
	while (env[ind])
		printf("%s\n", env[ind++]);
		
	return(1);
}

char	**ft_parse(t_data *data, char *line)
{
	char **dst;
	
	dst = (char**)calloc(100, sizeof(char));
	dst[0] = "export";
	dst[1] = "AAA=111";
	dst[2] = "BBB=222";
	// dst[3] = "env";
	// dst[4] = "env";
	// dst[5] = "env";
	// printf("%s\n", dst[0]);
	return (dst);
}

void	ft_loop(t_data *data, char **env)
{
	int		stat;
	char	**todo;
	char	*line;

	line = NULL;
	stat = 1;
	while (stat)
	{
		stat = 0;
		ft_putstr_fd("minihell> ", 1);
		get_next_line(0, &line);
		if ((todo = ft_parse(data, line)))
			stat = ft_exe(data, todo, env);
		// printf("%s\n", line);
		free(line);
		line = NULL;
	}
}

int		main(int argc, char **argv, char **envp)
{
	t_data		*data;
	char		**env;
	int ind = 0;
	
	env = ft_set_env(envp, 0, 0);
	// while (dup[ind])
	// 	printf("%s\n", dup[ind++]);
	ft_loop(data, env);
	return (0);
}