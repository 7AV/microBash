#include "../microBash.h"

void	ft_pwd(void)
{
	char	*tmp;

	tmp = getcwd(NULL, 42);
	ft_putendl_fd(tmp, 1);
	free(tmp);
}
