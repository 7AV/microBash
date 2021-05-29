/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:20:13 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/13 17:41:47 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error_synt(char *arg)
{
	g_exit = 258;
	ft_putstr_fd("minihell: Syntax error near unexpected token `",
	STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}

void	ft_error_cmd(char *arg, int flag)
{
	g_exit = 127;
	ft_putstr_fd("minihell: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	if (ft_strchr(arg, '/') || flag)
		ft_putendl_fd(": No such file or directory.", STDERR_FILENO);
	else
		ft_putendl_fd(": Command not found.", STDERR_FILENO);
}

void	ft_error_cd(char *arg)
{
	g_exit = 1;
	if (arg)
	{
		ft_putstr_fd("minihell: cd: ", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory.", STDERR_FILENO);
	}
	!arg ? ft_putendl_fd("minihell: cd: HOME not set", STDERR_FILENO) : 0;
}

void	ft_error_exit(char *arg)
{
	ft_putstr_fd("minihell: Exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	exit(255);
}

void	ft_error(int error)
{
	if (error == ER_MALC)
		ft_putendl_fd("minihell: Cannot allocate memory.", STDERR_FILENO);
	else if (error == ER_FORK)
		ft_errno();
	else if (error == ER_EXEC)
	{
		ft_errno();
		g_exit = 126;
	}
	else if (error == ER_FILE)
	{
		g_exit = 1;
		ft_errno();
	}
}
