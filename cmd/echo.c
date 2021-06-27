#include "../microBash.h"

void	ft_echo(char **arg)
{
	arg[1] ? ft_putstr_fd(arg[1], 1) : 0;
}
