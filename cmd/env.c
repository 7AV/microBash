/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:52:26 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/14 16:24:30 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(char **env)
{
	int		ind;

	ind = 0;
	while (env[ind])
	{
		if (ft_strrchr(env[ind], '='))
			ft_putendl_fd(env[ind], 1);
		ind++;
	}
}
