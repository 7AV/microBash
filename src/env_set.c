/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:30:41 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/14 16:04:18 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_valid_exp(char **env, int toggle, char *arg)
{
	int		ind;
	char	*tmp;

	ind = 0;
	while (env[ind])
	{
		if (!(ft_strncmp(env[ind], arg, ft_strlen(arg))) && !toggle &&
		(env[ind][ft_strlen(arg)] == '=') && !ft_strchr(arg, '='))
			return (2);
		if (!(ft_strncmp(env[ind], arg, ft_strnnchr(env[ind], '='))) &&
		toggle && (ft_strnnchr(env[ind], '=') == ft_strnnchr(arg, '=')))
		{
			tmp = env[ind];
			env[ind] = ft_libstrdup(MAGIC);
			free(tmp);
			return (1);
		}
		ind++;
	}
	return (0);
}

char	**ft_add_var(char **src, char **dst, char *var)
{
	int		ind;

	ind = 0;
	while (src[ind])
	{
		if (!(dst[ind] = ft_libstrdup(src[ind])))
			ft_error(ER_MALC);
		ind++;
	}
	if (!(dst[ind] = ft_libstrdup(var)))
		ft_error(ER_MALC);
	dst[ind + 1] = NULL;
	ft_free(src);
	return (dst);
}

char	**ft_del_var(char **src, char **dst)
{
	int		ind;

	ind = 0;
	while (ft_strncmp(src[ind], MAGIC, ft_strlen(MAGIC)))
	{
		if (!(dst[ind] = ft_strdup_pars(src[ind])))
			ft_error(ER_MALC);
		ind++;
	}
	while (src[ind + 1])
	{
		if (!(dst[ind] = ft_strdup_pars(src[ind + 1])))
			ft_error(ER_MALC);
		ind++;
	}
	dst[ind] = NULL;
	ft_free(src);
	return (dst);
}

char	**ft_set_env(char **envp, int toggle, char *var)
{
	int		ind;
	char	**dst;

	ind = 0;
	while (envp[ind])
		ind++;
	ind += toggle;
	if (!(dst = ft_calloc(ind + 1, sizeof(char*))))
		ft_error(ER_MALC);
	if (toggle > 0)
		dst = ft_add_var(envp, dst, var);
	else if (toggle < 0)
		dst = ft_del_var(envp, dst);
	else
	{
		ind = 0;
		while (envp[ind])
		{
			if (!(dst[ind] = ft_libstrdup(envp[ind])))
				ft_error(ER_MALC);
			ind++;
		}
		dst[ind] = NULL;
	}
	return (dst);
}
