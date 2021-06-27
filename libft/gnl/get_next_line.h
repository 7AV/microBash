#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strdup_gnl(const char *s1);
char	*ft_strjoin_gnl(char *s1, char const *s2);
int		get_next_line(char **line);
int		ft_strlen_gnl(const char *s);

#endif
