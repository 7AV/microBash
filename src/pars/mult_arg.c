#include "../microBash.h"

char	**char_free(char **res, int i)
{
	while (i > 1)
		free(res[--i]);
	free(res);
	return (NULL);
}

int		arg_count(char *str)
{
	int		i;
	int		count;
	int		word;
	t_flags	flag;

	i = 0;
	count = 0;
	word = 0;
	flags_init(&flag);
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && flag.block_flag == 1)
		{
			if (word)
				count++;
			word = 0;
		}
		else
			word = 1;
		esc_flags(&flag, str[i]);
		i++;
	}
	count += word;
	return (count);
}

char	*find_arg(char *str, int *i)
{
	char		*tmp;
	t_flags		flag;

	flags_init(&flag);
	tmp = ft_strdup_pars("");
	skip_spaces(str, i);
	while (str[*i] != '\0')
	{
		if (str[*i] == ' ' && flag.block_flag == 1)
			break ;
		tmp = ft_str_single_join(tmp, str[*i]);
		esc_flags(&flag, str[*i]);
		*i = *i + 1;
	}
	return (tmp);
}

char	*string_refact(char *s, char **env)
{
	t_string	i;
	char		*res;

	string_flags_init(&i, 1);
	res = ft_strdup_pars("");
	while (s[i.i] != '\0')
	{
		res = res_fill(s, res, &i, env);
		i.i++;
	}
	return (res);
}

char	**arg_to_mult_processing(t_list_block *tmp, char **env)
{
	char		**res;

	if (!(ft_strncmp(tmp->cmd, "echo", 5)))
	{
		if (!(res = ft_calloc(3, sizeof(char*))))
			return (NULL);
		if (!(res[0] = ft_strdup_pars(tmp->cmd)))
			return (char_free(res, 0));
		if (!(res[1] = echo_processing(tmp, env)))
			return (char_free(res, 1));
	}
	else
		res = basic_mult_arg(tmp, env);
	return (res);
}
