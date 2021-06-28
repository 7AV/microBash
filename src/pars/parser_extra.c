#include "../microBash.h"

void	set_flag(char *str, int *i, t_list_block *data)
{
	char	c;
	char	next;

	c = str[0];
	if (c != '\0')
		next = str[1];
	if (c == '|')
		data->pipe_flag = 1;
	else if (c == '>' && next != '>')
		data->redir_flag = 1;
	else if (c == '>' && next == '>')
	{
		data->double_redir_flag = 1;
		*i = *i + 1;
	}
	else if (c == '<')
		data->back_redir_flag = 1;
}

void	flags_init(t_flags *data)
{
	data->block_flag = 1;
	data->s_qoutes_flag = 1;
	data->d_qoutes_flag = 1;
	data->slash_flag = 1;
}

void	esc_flags(t_flags *flag, char c)
{
	if (c == '\"' && flag->slash_flag == 1)
		flag->d_qoutes_flag = (flag->d_qoutes_flag == 0) ? 1 : 0;
	if (c == '\'' && flag->slash_flag == 1)
		flag->s_qoutes_flag = (flag->s_qoutes_flag == 0) ? 1 : 0;
	flag->slash_flag = (c == '\\') ? 0 : 1;
	flag->block_flag = flag->slash_flag * flag->s_qoutes_flag \
	* flag->d_qoutes_flag;
}
