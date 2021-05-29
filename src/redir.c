/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:35:07 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/15 15:29:22 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_back_redir_execut(t_list_block **data, char ***env, int fd_save)
{
	int				fd;
	t_list_block	*tmp;

	tmp = *data;
	while ((*data)->back_redir_flag)
	{
		fd = open((*data)->next->cmd, O_RDONLY);
		((*data)->next->back_redir_flag) ? close(fd) : 0;
		(*data) = (*data)->next;
	}
	dup2(fd, 0);
	ft_execut(tmp, env);
	dup2(fd_save, 0);
	close(fd);
}

int		ft_trunc_append(t_list_block *data)
{
	int		fd;

	fd = 0;
	if (data->redir_flag)
		fd = open(data->next->cmd, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else if (data->double_redir_flag)
		fd = open(data->next->cmd, O_CREAT | O_WRONLY | O_APPEND, 0777);
	return (fd);
}

void	ft_redir_execut(t_list_block **data, char ***env)
{
	int				fd;
	int				fd_save;
	t_list_block	*tmp;

	tmp = *data;
	fd_save = dup(1);
	while (((*data)->redir_flag) || ((*data)->double_redir_flag))
	{
		fd = ft_trunc_append(*data);
		(((*data)->next->redir_flag) || ((*data)->next->double_redir_flag)) ?
		close(fd) : 0;
		(*data) = (*data)->next;
	}
	dup2(fd, 1);
	ft_execut(tmp, env);
	dup2(fd_save, 1);
	close(fd_save);
	close(fd);
}
