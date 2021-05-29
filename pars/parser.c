/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:16:04 by dwillett          #+#    #+#             */
/*   Updated: 2021/02/14 16:13:27 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	skip_spaces(char *str, int *i)
{
	while (str[*i] == ' ' && str[*i] != '\0')
		*i = *i + 1;
}

int		end_of_the_command(char c, int i)
{
	if (c == '\0')
		return (1);
	if (c == ';' || c == '|' || c == '>' || c == '<' || c == ' ')
		return (i);
	return (0);
}

int		end_of_the_block(char c, int i)
{
	if (c == '\0')
		return (1);
	if (c == ';' || c == '|' || c == '>' || c == '<')
		return (i);
	return (0);
}

char	*create_string(char *dest, char *src, int flag, int *i)
{
	char	tmp[2];
	int		(*check)(char, int);
	t_flags	flags;

	tmp[1] = '\0';
	flags_init(&flags);
	check = (flag == 1) ? end_of_the_block : end_of_the_command;
	if (flag == 2)
		check = end_of_the_name;
	while (!(check(src[*i], flags.block_flag)))
	{
		esc_flags(&flags, src[*i]);
		tmp[0] = src[*i];
		if (!(dest = ft_strjoin_pars(dest, tmp)))
			return (NULL);
		*i = *i + 1;
	}
	return (dest);
}

int		parser(char *str, t_list_block **head)
{
	int				i;
	t_list_block	*new;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(new = newblocklst()))
			return (-1);
		blocklstadd_back(head, new);
		skip_spaces(str, &i);
		if ((new->cmd = create_string(new->cmd, str, 0, &i)) == NULL)
			return (blocklstclear(*head));
		if (str[i] == ' ')
		{
			skip_spaces(str, &i);
			if ((new->arg = create_string(new->arg, str, 1, &i)) == NULL)
				return (blocklstclear(*head));
		}
		set_flag(str + i, &i, new);
		if (str[i] != '\0')
			i++;
	}
	return (0);
}
