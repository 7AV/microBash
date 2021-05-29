/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:41:11 by dwillett          #+#    #+#             */
/*   Updated: 2021/02/15 15:44:47 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
