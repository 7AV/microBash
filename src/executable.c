#include "../microBash.h"

void	ft_exit_status(int stat_loc)
{
	if (WIFSIGNALED(stat_loc))
	{
		WTERMSIG(stat_loc) == 2 ? g_exit = 130 : 0;
		WTERMSIG(stat_loc) == 3 ? g_exit = 131 : 0;
		WTERMSIG(stat_loc) == 3 ? ft_putstr_fd("Quit: 3", 1) : 0;
		ft_putendl_fd("", 1);
	}
	!WIFSIGNALED(stat_loc) ? g_exit = WEXITSTATUS(stat_loc) : 0;
}

void	ft_execut_fork(char *path, char **mult_arg, char **env)
{
	pid_t	pid;
	int		stat_loc;

	if ((pid = fork()) < 0)
		ft_error(ER_FORK);
	if (pid == 0)
	{
		if (execve(path, mult_arg, env) == -1)
		{
			ft_error(ER_EXEC);
			exit(WTERMSIG(stat_loc));
		}
	}
	else
	{
		ft_sig_off();
		wait(&stat_loc);
		ft_exit_status(stat_loc);
		ft_sig_on();
	}
}

int		ft_find_exe_part2(char *cmd, char **path, char **mult_arg, char **env)
{
	int			ind;
	struct stat	stats;

	ind = 0;
	while (path[ind])
	{
		if (!(path[ind] = ft_strjoin_pars(path[ind], "/")))
			ft_error(ER_MALC);
		if (!(path[ind] = ft_strjoin_pars(path[ind], cmd)))
			ft_error(ER_MALC);
		cmd = (stat(path[ind], &stats)) ? cmd : path[ind];
		if (!(stat(path[ind], &stats)))
		{
			ft_execut_fork(cmd, mult_arg, env);
			return (1);
		}
		ind++;
	}
	return (0);
}

void	ft_find_exe(char *cmd, char **mult_arg, char **env)
{
	char		**path;
	int			ind;

	ind = 0;
	while (env[ind] && ft_strncmp(env[ind], "PATH=", 5))
		ind++;
	if (!env[ind])
	{
		ft_error_cmd(mult_arg[0], 1);
		return ;
	}
	if (!(path = ft_split(env[ind] + 5, ':')))
		ft_error(ER_MALC);
	if (!(ft_find_exe_part2(cmd, path, mult_arg, env)))
		ft_error_cmd(mult_arg[0], 0);
	ft_free(path);
}
