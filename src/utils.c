#include "../microBash.h"

int		ft_strnnchr(char *str, int c)
{
	int		index;

	if ((char)c == '\0')
		return (ft_strlen(str));
	index = 0;
	while (index < ft_strlen(str))
	{
		if (*(str + index) == c)
			return (index);
		index++;
	}
	return (index);
}

int		ft_strnchr(char *str, int c)
{
	int		index;

	if ((char)c == '\0')
		return (ft_strlen(str));
	index = 0;
	while (index < ft_strlen(str))
	{
		if (*(str + index) == c)
			return (index + 1);
		index++;
	}
	return (index);
}

void	ft_errno(void)
{
	char	*str;

	str = strerror(errno);
	ft_putstr_fd("microBash: ", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
}

void	ft_free(char **trash)
{
	int		ind;

	ind = 0;
	while (trash[ind])
	{
		free(trash[ind]);
		ind++;
	}
	free(trash);
}
