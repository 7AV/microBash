#include "../microBash.h"

void	ft_sig_ctrl_c(int signal)
{
	if (signal)
		;
	g_exit = 1;
	ft_putendl_fd("\b\b  \b\b", 1);
	ft_putstr_fd("microBash> ", 1);
	g_dce = 1;
}

void	ft_sig_ctrl_slash(int signal)
{
	if (signal)
		;
	g_exit = 0;
	ft_putstr_fd("\b\b  \b\b", 1);
}

void	ft_sig_off(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_sig_on(void)
{
	signal(SIGINT, ft_sig_ctrl_c);
	signal(SIGQUIT, ft_sig_ctrl_slash);
}
