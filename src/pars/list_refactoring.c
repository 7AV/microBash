#include "../microBash.h"

int	syntax_check(t_list_block *head, char **error_string)
{
	t_list_block	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->prev && !(ft_strncmp(tmp->cmd, "", 1)))
			return (syntax_error(tmp, error_string, 1));
		else if (tmp->next && !(ft_strncmp(tmp->cmd, "", 1)))
		{
			if (!tmp->back_redir_flag && !tmp->redir_flag && \
			!tmp->double_redir_flag)
				return (syntax_error(tmp, error_string, 2));
		}
		else if (tmp->next == NULL)
		{
			if (tmp->back_redir_flag || tmp->redir_flag || \
			tmp->double_redir_flag || tmp->pipe_flag)
				return (syntax_error(tmp, error_string, 3));
		}
		tmp = tmp->next;
	}
	return (syntax_error(tmp, error_string, 0));
}

int	flag_check(t_list_block *tmp, int flag)
{
	if (flag == 1)
		return (tmp->redir_flag || tmp->double_redir_flag);
	return (tmp->back_redir_flag);
}

int	arg_collection(t_list_block *head, int flag)
{
	while (head->next && flag_check(head, flag))
		head = head->next;
	while (head->prev && flag_check(head->prev, flag))
	{
		head->prev->arg = ft_strjoin_pars(head->prev->arg, " ");
		head->prev->arg = ft_strjoin_pars(head->prev->arg, head->arg);
		head = head->prev;
	}
	if (!head->arg)
		return (-1);
	return (0);
}

int	list_refactor(t_list_block *head)
{
	t_list_block	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->redir_flag || tmp->double_redir_flag)
		{
			if ((arg_collection(tmp, 1)) == -1)
				return (-1);
			while (tmp->next && (tmp->redir_flag || tmp->double_redir_flag))
				tmp = tmp->next;
		}
		else if (tmp->back_redir_flag)
		{
			if ((arg_collection(tmp, 0)) == -1)
				return (-1);
			while (tmp->next && tmp->back_redir_flag)
				tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	return (0);
}
