/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:37:16 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/02 16:40:23 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_add_var(char **src, char **dst, char *var)
{
	int		ind;

	ind = 0;
	while (src[ind])
	{
		dst[ind] = ft_libstrdup(src[ind]);
		ind++;
	}
	dst[ind] = ft_libstrdup(var);
	dst[ind + 1] = NULL;
	return (dst);
}

char	**ft_del_var(char **src, char **dst, char *var)
{
	int		ind;

	ind = 0;
	while (ft_strncmp(src[ind], var, ft_strlen(var)))
	{
		dst[ind] = src[ind];
		ind++;
	}
	while (src[ind + 1])
	{
		dst[ind] = src[ind + 1];
		ind++;
	}
	dst[ind] = NULL;
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
	dst = ft_calloc(ind + 1, sizeof(char*));
	if (toggle > 0)
		dst = ft_add_var(envp, dst, var);
	else if (toggle < 0)
		dst = ft_del_var(envp, dst, var);
	else
	{
		ind = 0;
		while (envp[ind])
		{
			dst[ind] = ft_libstrdup(envp[ind]);
			ind++;
		}
		dst[ind] = NULL;
	}
	return (dst);
}

void	ft_free(char **trash)
{
	int		ind;

	ind = 0;
	while (trash[ind])
	{
		free(trash[ind]);
		ind++;
	}
	free(trash);
}
