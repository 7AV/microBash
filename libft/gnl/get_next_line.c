#include "get_next_line.h"

int		ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_dce(void)
{
	write(1, "exit\n", 5);
	exit(0);
}

int		get_next_line(char **line)
{
	char		buf[2];
	int			i;

	if (!(*line = ft_strdup_gnl("\0")))
		return (-1);
	i = read(0, buf, 1);
	buf[1] = '\0';
	while (buf[0] != '\n' && i != 0)
	{
		if (!(*line = ft_strjoin_gnl(*line, buf)))
			return (-1);
		i = read(0, buf, 1);
		buf[1] = '\0';
		if (!i)
		{
			write(1, "  \b\b", 4);
			buf[0] = '\0';
		}
		i = 1;
	}
	if (!i && (**line == 0))
		ft_dce();
	return (1);
}
