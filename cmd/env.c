/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:52:26 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/02 10:53:24 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(char **arg, char **env)
{
	int		ind;

	ind = 0;
	if (!arg[1])
	{
		while (env[ind])
		{
			ft_putendl_fd(env[ind], 1);
			ind++;
		}
	}
	// else
	// 	error
}
