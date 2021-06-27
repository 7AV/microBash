#include "microBash.h"

int		main(int argc, char **argv, char **envp)
{
	char	**env;

	if (argv[argc - 1])
		;
	env = ft_set_env(envp, 0, 0);
	g_exit = 0;
	g_dce = 0;
	ft_sig_on();
	ft_loop(env);
	return (0);
}
