/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:51:20 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/02 10:58:17 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_set_env_path(char **env, char *dest)
{
	int		ind;
	char	*tmp;

	ind = 0;
	while (ft_strncmp(env[ind], "PWD=", 4))
		ind++;
	tmp = env[ind];
	// printf("%s | ", env[ind]);
	env[ind] = ft_strjoin("PWD=", dest);
	free(tmp);
	// printf("%s\n", env[ind]);
}

char	*ft_home(char **env)
{
	int		ind;

	ind = 0;
	while (ft_strncmp(env[ind], "HOME=", 5))
		ind++;
	return (env[ind] ? env[ind] + 5 : NULL);
}

void	ft_cd(char **arg, char **env)
{
	char		*current;
	char		*dest;
	struct stat	stats;

	current = getcwd(NULL, 42);
	dest = (arg[1]) ? arg[1] : ft_home(env);
	if (!(stat(dest, &stats)))
	{
		chdir(dest);
		ft_set_env_path(env, dest);
	}
	// else
	// 	error
	// printf("%s\n", dest);
	free(current);
}
