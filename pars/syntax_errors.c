/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:53:13 by dwillett          #+#    #+#             */
/*   Updated: 2021/02/14 16:10:50 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	syntax_error(t_list_block *tmp, char **line, int flag)
{
	if (flag == 0)
		return (0);
	else if (flag == 1)
	{
		if (tmp->back_redir_flag)
			*line = ft_strdup_pars("<");
		else if (tmp->redir_flag)
			*line = ft_strdup_pars(">");
		else if (tmp->pipe_flag)
			*line = ft_strdup_pars("|");
		else
			*line = ft_strdup_pars("newline");
	}
	else if (flag == 2)
	{
		if (tmp->pipe_flag)
			*line = ft_strdup_pars("|");
		else
			*line = ft_strdup_pars(";");
	}
	else
		*line = ft_strdup_pars("newline");
	if (!(*line))
		return (-1);
	return (1);
}
