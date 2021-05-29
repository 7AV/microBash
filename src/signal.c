/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:36:16 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/15 15:46:58 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_sig_ctrl_c(int signal)
{
	if (signal)
		;
	g_exit = 1;
	ft_putendl_fd("\b\b  \b\b", 1);
	ft_putstr_fd("minihell> ", 1);
	g_dce = 1;
}

void	ft_sig_ctrl_slash(int signal)
{
	if (signal)
		;
	g_exit = 0;
	ft_putstr_fd("\b\b  \b\b", 1);
}

void	ft_sig_off(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_sig_on(void)
{
	signal(SIGINT, ft_sig_ctrl_c);
	signal(SIGQUIT, ft_sig_ctrl_slash);
}
