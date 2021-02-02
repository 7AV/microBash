/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:45:51 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/02 17:09:15 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include "libft/gnl/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/stat.h>

# include <stdio.h>

void		ft_exit(char **arg);
void		ft_unset(char **arg, char ***env);
void		ft_export(char **arg, char ***env);
void		ft_env(char **arg, char **env);
void		ft_free(char **trash);
char		**ft_set_env(char **envp, int toggle, char *var);
void		ft_cd(char **arg, char **env);
void		ft_pwd();
void		ft_echo(char **arg);
int			get_next_line(const int fd, char **line);
char		*ft_libstrdup(const char *s1);
int			main(int argc, char **argv, char **envp);

#endif
