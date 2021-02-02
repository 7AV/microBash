/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:12:45 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/02 10:53:15 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char **arg)
{
	int		ind;
	int		flag;

	flag = 0;
	ind = 0;
	if (arg[1])
	{
		while (arg[++ind] && !ft_strncmp(arg[ind], "-n", 2))
			flag++;
		while (arg[ind])
		{
			ft_putstr_fd(arg[ind++], 1);
			arg[ind] ? ft_putchar_fd(' ', 1) : 0;
		}
		flag ? 0 : ft_putchar_fd('\n', 1);
	}
}
