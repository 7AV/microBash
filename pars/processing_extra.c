#include "../microBash.h"

int		is_it_spec_symbol(char *c)
{
	if (c[0] == '\\' || c[0] == '\"' || c[0] == '\'')
		return (1);
	else if (c[0] == '$' && c[1] != ' ' && c[1] != '\0')
		return (1);
	return (0);
}

char	*dollar_sign_extra(char *name, char *res, char **env)
{
	char	*volume;
	int		j;
	int		len;

	len = ft_strlen(name);
	j = 0;
	while (env[j])
	{
		if (!(ft_strncmp(env[j], name, len)) && env[j][len] == '=')
		{
			if (!(volume = ft_substr(env[j], len + 1,
			ft_strlen(env[j]) - len)))
				return (NULL);
			res = ft_strjoin_pars(res, volume);
			free(volume);
			return (res);
		}
		j++;
	}
	return (res);
}

char	*echo_question_sign(int *i, char *res)
{
	char	*tmp;

	*i = *i + 1;
	tmp = ft_itoa(g_exit);
	res = ft_strjoin_pars(res, tmp);
	if (tmp)
		free(tmp);
	return (res);
}
