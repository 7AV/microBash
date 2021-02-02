/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:37:16 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/02 12:43:59 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_add_var(char **env, char *var)
{
	
}

char	**ft_del_var(char **env, char *var)
{
	
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
		ft_add_var(envp, var);
	else if (toggle < 0)
		ft_del_var(envp, var);
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
