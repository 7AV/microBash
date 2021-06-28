#include "../microBash.h"

void	n_flag_search(int *n_flag, int *start_flag, int *i, char *str)
{
	if (!(ft_strncmp(str + *i, "-n ", 3)) || !(ft_strncmp(str + *i, "-n", 3)))
	{
		*i = *i + 1;
		*n_flag = 1;
	}
	else if (str[*i] != ' ')
	{
		*start_flag = 1;
		*i = *i - 1;
	}
}

void	string_flags_init(t_string *data, int skip)
{
	data->i = 0;
	data->n_flag = 0;
	data->start_flag = 0;
	data->space_flag = 0;
	data->skip_flag = skip;
}

char	*echo_processing(t_list_block *tmp, char **env)
{
	t_string		prm;
	char			*res;

	string_flags_init(&prm, 0);
	if (!(tmp->arg = ft_strtrim_pars(tmp->arg, " ")))
		return (NULL);
	if (!(res = ft_strdup_pars("")))
		return (NULL);
	while (tmp->arg[prm.i] != '\0')
	{
		if (prm.start_flag)
			res = res_fill(tmp->arg, res, &prm, env);
		else
			n_flag_search(&prm.n_flag, &prm.start_flag, &prm.i, tmp->arg);
		prm.i++;
	}
	if (prm.n_flag == 0)
		res = ft_strjoin_pars(res, "\n");
	return (res);
}
