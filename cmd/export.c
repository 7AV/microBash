/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:53:00 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/02 16:28:45 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_sort_export(char **env)
{
	int		ind;
	int		flag;
	char	*tmp;
	char	**t_env;

	t_env = ft_set_env(env, 0, 0);
	flag = 1;
	while (flag)
	{
		flag = 0;
		ind = 0;
		while (t_env[ind + 1])
		{
			if (ft_strncmp(t_env[ind], t_env[ind + 1],
			ft_strlen(t_env[ind]) + 1) > 0)
			{
				tmp = t_env[ind + 1];
				t_env[ind + 1] = t_env[ind];
				t_env[ind] = tmp;
				flag++;
			}
			ind++;
		}
	}
	return (t_env);
}

void	ft_put_export(char **env)
{
	char	**t_env;
	int		ind;
	
	t_env = ft_sort_export(env);
	ind = 0;
	while (t_env[ind])
	{
		// do we need processing " " ?
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(t_env[ind], 1);
		ind++;
	}
	ft_free(t_env);
	//exit
}

void	ft_export(char **arg, char ***env)
{
	int		ind;

	ind = 1;
	!(arg[ind]) ? ft_put_export(*env) : 0;
	while (arg[ind])
	{
		*env = ft_set_env(*env, 1, arg[ind]);
		// int inx=0;
		// while (env[inx])
		// 	printf("%s\n", env[inx++]);
		ind++;
		
	}
}
