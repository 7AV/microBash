/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:45:51 by sbudding          #+#    #+#             */
/*   Updated: 2021/02/15 15:46:48 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "libft/gnl/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <dirent.h>

# define ER_MALC 0
# define ER_FORK 1
# define ER_EXEC 2
# define ER_FILE 3
# define MAGIC "its_some_kind_of_magic"

typedef	struct				s_string
{
	int						space_flag;
	int						n_flag;
	int						start_flag;
	int						skip_flag;
	int						i;
}							t_string;

typedef	struct				s_flags
{
	int						block_flag;
	int						s_qoutes_flag;
	int						slash_flag;
	int						d_qoutes_flag;
}							t_flags;

typedef	struct				s_list_block
{
	struct s_list_block		*next;
	struct s_list_block		*prev;
	char					*cmd;
	char					*arg;
	char					**mult_arg;
	int						pipe_flag;
	int						redir_flag;
	int						back_redir_flag;
	int						double_redir_flag;
}							t_list_block;

int							g_exit;
int							g_dce;

void						ft_execut(t_list_block *data, char ***env);
void						ft_pipe_execut(t_list_block *data, char ***env);
void						ft_list_execut(t_list_block *data, char ***env);
void						ft_processing(char *line, t_list_block **data,
char ***env, char **error);
void						ft_loop(char **env);
int							ft_strnnchr(char *str, int c);
void						ft_error(int error);
void						ft_errno(void);
void						ft_error_exit(char *arg);
void						ft_error_cd(char *arg);
void						ft_error_synt(char *arg);
void						ft_error_cmd(char *arg, int flag);
void						ft_execut_fork(char *path, char **mult_arg,
char **env);
void						ft_find_exe(char *cmd, char **mult_arg, char **env);
void						ft_execut(t_list_block *data, char ***env);
void						ft_back_redir_execut(t_list_block **data,
char ***env, int fd_save);
void						ft_redir_execut(t_list_block **data, char ***env);
void						ft_sig_ctrl_c(int signal);
void						ft_sig_ctrl_slash(int signal);
void						ft_sig_off(void);
void						ft_sig_on(void);
void						ft_put_export(char **env);
int							ft_valid_exp(char **env, int toggle, char *arg);
int							ft_strnchr(char *src, int c);
void						ft_error(int error);
void						ft_exit(char **arg);
void						ft_unset(char **arg, char ***env);
void						ft_export(char **arg, char ***env);
void						ft_env(char **env);
void						ft_free(char **trash);
char						**ft_set_env(char **envp, int toggle, char *var);
void						ft_cd(char **arg, char **env);
void						ft_pwd();
void						ft_echo(char **arg);
int							get_next_line(char **line);
char						*ft_libstrdup(const char *s1);
char						**ft_del_var(char **src, char **dst);

/*
** hello
*/

t_list_block				*newblocklst(void);
void						blocklstadd_back(t_list_block **head,
t_list_block *new);
void						blocklstdelete(t_list_block *tmp);
void						skip_spaces(char *str, int *i);
void						set_flag(char *str, int *i,
t_list_block *data);
void						n_flag_search(int *n_flag, int *start_flag,
int *i, char *str);
void						string_flags_init(t_string *data, int skip);
void						flags_init(t_flags *data);
void						esc_flags(t_flags *flag, char c);
char						**char_free(char **res, int i);
char						**basic_mult_arg(t_list_block *tmp, char **env);
char						**arg_to_mult_processing(t_list_block *tmp,
char **env);
char						*create_string(char *dest, char *src, int flag,
int *i);
char						*ft_str_single_join(char *s1, char c);
char						*single_quotes(char *str, char *res, int *i);
char						*double_quotes(char *str, char *res, int *i,
char **env);
char						*dollar_sign(char *str, char *res, int *i,
char **env);
char						*spec_symbols(char *str, char *res, int *i,
char **env);
char						*res_fill(char *str, char *res, t_string *tmp,
char **env);
char						*find_arg(char *str, int *i);
char						*string_refact(char *s, char **env);
char						*echo_processing(t_list_block *tmp, char **env);
int							blocklstclear(t_list_block *head);
int							end_of_the_command(char c, int i);
int							end_of_the_block(char c, int i);
int							end_of_the_name(char c, int i);
int							is_it_spec_symbol(char *c);
int							parser(char *str, t_list_block **head);
int							func_selection(t_list_block *tmp, char **env);
int							processing(t_list_block *head, char **env);
int							arg_count(char *str);
int							block_refactoring(t_list_block *tmp, char **env);

/*
** list refactoring
*/

int							syntax_check(t_list_block *head,
char **error_string);
int							flag_check(t_list_block *tmp, int flag);
int							arg_collection(t_list_block *head, int flag);
int							list_refactor(t_list_block *head);

/*
** syntax_error
*/

int							syntax_error(t_list_block *tmp, char **line,
int flag);

/*
** processing_extra
*/

char						*echo_question_sign(int *i, char *res);
char						*dollar_sign_extra(char *name, char *res,
char **env);

#endif
