/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:50:19 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/11 15:54:58 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strdup_gnl(const char *s1);
char	*ft_strjoin_gnl(char *s1, char const *s2);
int		get_next_line(char **line);
int		ft_strlen_gnl(const char *s);

#endif
