#include "../microBash.h"

void	ft_env(char **env)
{
	int		ind;

	ind = 0;
	while (env[ind])
	{
		if (ft_strrchr(env[ind], '='))
			ft_putendl_fd(env[ind], 1);
		ind++;
	}
}
