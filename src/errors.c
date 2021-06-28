#include "microBash.h"

void	ft_error_synt(char *arg)
{
	g_exit = 258;
	ft_putstr_fd("microBash: Syntax error near unexpected token `",
	STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}

void	ft_error_cmd(char *arg, int flag)
{
	g_exit = 127;
	ft_putstr_fd("microBash: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	if (ft_strchr(arg, '/') || flag)
		ft_putendl_fd(": No such file or directory.", STDERR_FILENO);
	else
		ft_putendl_fd(": Command not found.", STDERR_FILENO);
}

void	ft_error_cd(char *arg)
{
	g_exit = 1;
	if (arg)
	{
		ft_putstr_fd("microBash: cd: ", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory.", STDERR_FILENO);
	}
	!arg ? ft_putendl_fd("microBash: cd: HOME not set", STDERR_FILENO) : 0;
}

void	ft_error_exit(char *arg)
{
	ft_putstr_fd("microBash: Exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	exit(255);
}

void	ft_error(int error)
{
	if (error == ER_MALC)
		ft_putendl_fd("microBash: Cannot allocate memory.", STDERR_FILENO);
	else if (error == ER_FORK)
		ft_errno();
	else if (error == ER_EXEC)
	{
		ft_errno();
		g_exit = 126;
	}
	else if (error == ER_FILE)
	{
		g_exit = 1;
		ft_errno();
	}
}
