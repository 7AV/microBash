/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:41:25 by dwillett          #+#    #+#             */
/*   Updated: 2021/02/13 12:09:37 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void			blocklstdelete(t_list_block *tmp)
{
	int	i;

	i = 0;
	if (tmp->cmd)
		free(tmp->cmd);
	if (tmp->arg)
		free(tmp->arg);
	if (tmp->mult_arg)
	{
		while (tmp->mult_arg[i])
			free(tmp->mult_arg[i++]);
		free(tmp->mult_arg);
	}
	free(tmp);
}

int				blocklstclear(t_list_block *head)
{
	t_list_block	*tmp;

	while (head)
	{
		tmp = head->next;
		blocklstdelete(head);
		head = tmp;
	}
	return (-1);
}

t_list_block	*newblocklst(void)
{
	t_list_block	*new;

	new = malloc(sizeof(t_list_block));
	if (!new)
		return (NULL);
	new->pipe_flag = 0;
	new->redir_flag = 0;
	new->back_redir_flag = 0;
	new->double_redir_flag = 0;
	new->next = NULL;
	new->prev = NULL;
	new->mult_arg = NULL;
	new->cmd = ft_strdup_pars("");
	new->arg = ft_strdup_pars("");
	if (new->cmd == NULL || new->arg == NULL)
	{
		blocklstclear(new);
		return (NULL);
	}
	return (new);
}

void			blocklstadd_back(t_list_block **head, t_list_block *new)
{
	t_list_block	*tmp;

	if (!head)
		return ;
	if (*head == NULL)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}
