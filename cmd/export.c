/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:53:00 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/13 17:11:31 by sbudding         ###   ########.fr       */
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

void	ft_put_kavichki_blat(char *arg)
{
	int		ind;

	ind = 0;
	while ((arg[ind] != '=') && arg[ind])
		write(1, &arg[ind++], 1);
	if (!arg[ind])
	{
		write(1, "\n", 1);
		return ;
	}
	write(1, &arg[ind++], 1);
	write(1, "\"", 1);
	while (arg[ind] != '\0')
		write(1, &arg[ind++], 1);
	write(1, "\"\n", 2);
}

void	ft_put_export(char **env)
{
	char	**t_env;
	int		ind;

	t_env = ft_sort_export(env);
	ind = 0;
	while (t_env[ind])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_put_kavichki_blat(t_env[ind]);
		ind++;
	}
	ft_free(t_env);
}

int		ft_error_exp_arg(char *arg)
{
	int		ind;

	ind = 0;
	while ((arg[ind] && arg[ind] != '=') || (arg[ind] == '=' && ind == 0))
	{
		if (((!ft_isalpha(arg[ind] && !ft_isdigit(arg[ind]) && arg[ind] != '_'))
		&& (ft_isdigit(arg[0]))) || (arg[ind] == '=' && ind == 0))
		{
			ft_putstr_fd("minihell: Export: `", STDERR_FILENO);
			ft_putstr_fd(arg, 1);
			ft_putendl_fd("': not a valid identifier.", STDERR_FILENO);
			return (1);
		}
		ind++;
	}
	return (0);
}

void	ft_export(char **arg, char ***env)
{
	int		ind;

	ind = 1;
	!(arg[ind]) ? ft_put_export(*env) : 0;
	while (arg[ind])
	{
		if (((ft_valid_exp(*env, 0, arg[ind]) == 2)) ||
		(ft_error_exp_arg(arg[ind])))
		{
			ind++;
			continue ;
		}
		if (ft_valid_exp(*env, 1, arg[ind]) == 1)
			*env = ft_set_env(*env, -1, arg[ind]);
		*env = ft_set_env(*env, 1, arg[ind]);
		ind++;
	}
}
