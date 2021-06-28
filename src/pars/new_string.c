#include "../microBash.h"

int		block_refactoring(t_list_block *tmp, char **env)
{
	char	*new;
	int		i;

	if (!(new = string_refact(tmp->cmd, env)))
		return (-1);
	free(tmp->cmd);
	if (arg_count(new) > 1)
	{
		i = 0;
		new = ft_strjoin_pars(new, " ");
		if (!(new = ft_strjoin_pars(new, tmp->arg)))
			return (-1);
		tmp->cmd = create_string(ft_strdup_pars(""), new, 0, &i);
		free(tmp->arg);
		tmp->arg = create_string(ft_strdup_pars(""), new, 1, &i);
		if (!tmp->cmd || !tmp->arg)
			return (-1);
	}
	else
		tmp->cmd = new;
	if (!(tmp->mult_arg = arg_to_mult_processing(tmp, env)))
		return (-1);
	return (0);
}

char	*ft_str_single_join(char *s1, char c)
{
	char	tmp[2];
	char	*res;

	tmp[0] = c;
	tmp[1] = '\0';
	return (res = ft_strjoin_pars(s1, tmp));
}

char	*res_fill(char *str, char *res, t_string *tmp, char **env)
{
	if (is_it_spec_symbol(str + tmp->i))
	{
		tmp->space_flag = 0;
		res = spec_symbols(str, res, &tmp->i, env);
	}
	else if (tmp->skip_flag == 0)
	{
		if ((tmp->space_flag == 1 && str[tmp->i] != ' ') || \
		tmp->space_flag
		== 0)
		{
			res = ft_str_single_join(res, str[tmp->i]);
			tmp->space_flag = (str[tmp->i] == ' ') ? 1 : 0;
		}
	}
	else
		res = ft_str_single_join(res, str[tmp->i]);
	return (res);
}
