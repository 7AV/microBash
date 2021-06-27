#include "../microBash.h"

void	ft_execut(t_list_block *data, char ***env)
{
	struct stat		stats;
	int				cnt;

	block_refactoring(data, *env);
	{
		cnt = 0;
		!(ft_strncmp(data->cmd, "echo", 4)) ? ft_echo(data->mult_arg) : cnt++;
		!(ft_strncmp(data->cmd, "pwd", 3)) ? ft_pwd() : cnt++;
		!(ft_strncmp(data->cmd, "cd", 2)) ? ft_cd(data->mult_arg, *env) : cnt++;
		!(ft_strncmp(data->cmd, "env", 3)) ? ft_env(*env) : cnt++;
		!(ft_strncmp(data->cmd, "export", 6)) ?
		ft_export(data->mult_arg, env) : cnt++;
		!(ft_strncmp(data->cmd, "unset", 5)) ?
		ft_unset(data->mult_arg, env) : cnt++;
		!(ft_strncmp(data->cmd, "exit", 4)) ? ft_exit(data->mult_arg) : cnt++;
		if (ft_strchr(data->cmd, '/') && stat(data->cmd, &stats))
		{
			ft_error_cmd(data->mult_arg[0], 0);
			return ;
		}
		if (cnt == 7)
			!(stat(data->cmd, &stats)) ?
			ft_execut_fork(data->cmd, data->mult_arg, *env) :
			ft_find_exe(data->cmd, data->mult_arg, *env);
	}
}

void	ft_pipe_execut(t_list_block *data, char ***env)
{
	int		fd[2];
	pid_t	pid;
	int		stat_loc;

	pipe(fd);
	if ((pid = fork()) < 0)
		ft_error(ER_FORK);
	else if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		ft_execut(data, env);
		close(fd[1]);
		exit(0);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[1]);
		wait(&stat_loc);
		close(fd[0]);
	}
}

void	ft_list_execut(t_list_block *data, char ***env)
{
	t_list_block	*tmp;
	int				fd_save;

	fd_save = dup(0);
	tmp = data;
	while (tmp)
	{
		if (tmp->pipe_flag)
			ft_pipe_execut(tmp, env);
		else if ((tmp->redir_flag) || (tmp->double_redir_flag))
		{
			ft_redir_execut(&tmp, env);
			dup2(fd_save, 0);
		}
		else if (tmp->back_redir_flag)
			ft_back_redir_execut(&tmp, env, fd_save);
		else
		{
			ft_execut(tmp, env);
			dup2(fd_save, 0);
		}
		tmp = tmp->next;
	}
	close(fd_save);
}

void	ft_processing(char *line, t_list_block **data, char ***env,
char **error)
{
	if (!(parser(line, data)))
	{
		if (syntax_check(*data, error) == 0)
			(list_refactor(*data) == 0) ?
			ft_list_execut(*data, env) : ft_error(ER_MALC);
		else if (!*error)
			ft_error(ER_MALC);
		else
			ft_error_synt(*error);
	}
	else
		ft_error(ER_MALC);
}

void	ft_loop(char **env)
{
	char			*line;
	char			*error;
	t_list_block	*data;

	line = NULL;
	data = NULL;
	while (2007)
	{
		ft_putstr_fd("microBash> ", 1);
		get_next_line(&line);
		data = NULL;
		if (g_dce == 1)
		{
			free(line);
			g_dce = 0;
			continue ;
		}
		ft_processing(line, &data, &env, &error);
		blocklstclear(data);
		free(line);
		line = NULL;
	}
}
