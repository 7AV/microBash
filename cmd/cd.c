/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:51:20 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/14 15:55:49 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_set_old_path(char **env)
{
	int		ind;
	char	*tmp;
	char	*oldpwd;

	ind = 0;
	while (env[ind] && ft_strncmp(env[ind], "OLDPWD=", 7))
		ind++;
	if (!env[ind])
		return ;
	tmp = env[ind];
	oldpwd = getcwd(NULL, 42);
	env[ind] = ft_strjoin("OLDPWD=", oldpwd);
	free(oldpwd);
	free(tmp);
}

void	ft_set_env_path(char **env)
{
	int		ind;
	char	*tmp;
	char	*pwd;

	ind = 0;
	while (env[ind] && ft_strncmp(env[ind], "PWD=", 4))
		ind++;
	if (!env[ind])
		return ;
	tmp = env[ind];
	pwd = getcwd(NULL, 42);
	env[ind] = ft_strjoin("PWD=", pwd);
	free(pwd);
	free(tmp);
}

char	*ft_home(char **arg, char **env)
{
	int		ind;

	ind = 0;
	while (env[ind] && ft_strncmp(env[ind], "HOME=", 5))
		ind++;
	if (!env[ind])
	{
		ft_error_cd(arg[1]);
		return (NULL);
	}
	return (env[ind] + 5);
}

void	ft_error_direct(char *arg)
{
	g_exit = 1;
	if (arg && !opendir(arg))
	{
		ft_putstr_fd("minihell: cd: ", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putendl_fd(": Not a directory.", STDERR_FILENO);
	}
}

void	ft_cd(char **arg, char **env)
{
	char			*dest;
	struct stat		stats;

	dest = (arg[1]) ? arg[1] : ft_home(arg, env);
	if (!dest)
		return ;
	if (!(stat(dest, &stats)))
	{
		ft_set_old_path(env);
		chdir(dest);
		ft_set_env_path(env);
		(open(dest, O_RDWR) != -1) ? ft_error_direct(dest) : 0;
	}
	else
		ft_error_cd(arg[1]);
}
