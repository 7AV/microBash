#include "../microBash.h"

char	*single_quotes(char *str, char *res, int *i)
{
	char	tmp[2];

	tmp[1] = '\0';
	while (str[*i] != '\'' && str[*i] != '\0')
	{
		tmp[0] = str[*i];
		if (!(res = ft_strjoin_pars(res, tmp)))
			return (NULL);
		*i = *i + 1;
	}
	return (res);
}

char	*double_quotes(char *str, char *res, int *i, char **env)
{
	char	tmp[2];

	tmp[1] = '\0';
	while (str[*i] != '\"' && str[*i] != '\0')
	{
		if (str[*i] == '\\')
		{
			if (str[*i + 1] == '\"' || str[*i + 1] == '$' || \
			str[*i + 1] == '\\')
				tmp[0] = str[++*i];
			else
				tmp[0] = str[*i];
			res = ft_strjoin_pars(res, tmp);
		}
		else if (str[*i] == '$' && (str[*i + 1] != ' ' && str[*i + 1] != '\0'))
		{
			*i = *i + 1;
			res = dollar_sign(str, res, i, env);
			*i = *i - 1;
		}
		else
			res = ft_str_single_join(res, str[*i]);
		*i = *i + 1;
	}
	return (res);
}

char	*dollar_sign(char *str, char *res, int *i, char **env)
{
	char	*name;

	if (!(name = create_string(ft_strdup_pars(""), str, 2, i)))
		return (NULL);
	if (str[*i] == '?' && name[0] == '\0')
		res = echo_question_sign(i, res);
	else
		res = dollar_sign_extra(name, res, env);
	free(name);
	return (res);
}

char	*spec_symbols(char *str, char *res, int *i, char **env)
{
	if (str[*i] == '\'')
	{
		*i = *i + 1;
		res = single_quotes(str, res, i);
	}
	else if (str[*i] == '\"')
	{
		*i = *i + 1;
		res = double_quotes(str, res, i, env);
	}
	else if (str[*i] == '\\')
	{
		*i = *i + 1;
		res = ft_str_single_join(res, str[*i]);
	}
	else if (str[*i] == '$' && (str[*i + 1] != ' ' && str[*i + 1] != '\0'))
	{
		*i = *i + 1;
		res = dollar_sign(str, res, i, env);
		*i = *i - 1;
	}
	return (res);
}

int		end_of_the_name(char c, int i)
{
	i = ft_isalnum(c);
	if (i == 0 && c == '_')
		i = 1;
	return (!i);
}
