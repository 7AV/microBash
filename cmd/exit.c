/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:54:05 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/12 17:18:54 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(char **arg)
{
	int		count;

	count = 0;
	while (arg[count])
		count++;
	ft_putendl_fd("exit", 1);
	count == 1 ? exit(0) : 0;
	count == 2 ? exit(ft_atoi(arg[1]) % 256) : 0;
	if (ft_isdigit(arg[1][0]) && arg[2])
		ft_putendl_fd("minihell: exit: too many arguments", 1);
	else if (arg[1] && arg[2])
		ft_error_exit(arg[1]);
}
