#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
	res = (char*)malloc(i);
	i = 0;
	j = 0;
	if (res)
	{
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			res[i++] = s2[j++];
		res[i] = '\0';
		free(s1);
		return (res);
	}
	free(s1);
	return (NULL);
}
