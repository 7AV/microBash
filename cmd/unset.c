#include "../microBash.h"

int		ft_error_uns_arg(char *arg)
{
	int		ind;

	ind = 0;
	while (arg[ind])
	{
		if ((!ft_isalpha(arg[ind]) && !ft_isdigit(arg[ind]) && arg[ind] != '_')
		|| ft_isdigit(arg[0]))
		{
			ft_putstr_fd("minihell: Unset: `", STDERR_FILENO);
			ft_putstr_fd(arg, 1);
			ft_putendl_fd("': not a valid identifier.", STDERR_FILENO);
			return (1);
		}
		ind++;
	}
	return (0);
}

int		ft_valid_uns(char **env, char *arg)
{
	int		ind;
	char	*tmp;

	ind = 0;
	while (env[ind])
	{
		if (!(ft_strncmp(env[ind], arg, ft_strlen(arg))) &&
		((env[ind][ft_strlen(arg)] == '\0') ||
		(env[ind][ft_strlen(arg)] == '=')))
		{
			tmp = env[ind];
			env[ind] = ft_libstrdup(MAGIC);
			free(tmp);
			return (1);
		}
		ind++;
	}
	return (0);
}

void	ft_unset(char **arg, char ***env)
{
	int		ind;

	ind = 1;
	while (arg[ind])
	{
		if (!(ft_error_uns_arg(arg[ind])))
			if (ft_valid_uns(*env, arg[ind]))
				*env = ft_set_env(*env, -1, arg[ind]);
		ind++;
	}
}
