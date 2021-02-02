/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:53:47 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/02 16:30:35 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(char **arg, char ***env)
{
	int		ind;

	ind = 1;
	while (arg[ind])
	{
		*env = ft_set_env(*env, -1, arg[ind]);
		ind++;
	}
}