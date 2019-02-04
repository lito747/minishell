/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exacute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:40:18 by mpytienk          #+#    #+#             */
/*   Updated: 2018/02/13 10:40:20 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	int		sis_exac(char **envd, char **argt, char **fpath)
{
	int			i;
	char		*path;
	struct stat buf;

	i = 0;
	while (fpath[i])
	{
		fpath[i] = path_join(fpath[i]);
		path = ft_strjoin(fpath[i], argt[0]);
		if (lstat(path, &buf) != -1)
		{
			to_fork(path, argt, envd);
			free(path);
			return (1);
		}
		free(path);
		i++;
	}
	return (0);
}

static int		exec_mod(char **envd, char **argt, char *pt)
{
	char		*path;
	char		**fpath;
	int			i;

	(void)pt;
	i = get_env_pos(envd, "PATH");
	if (i != -1)
	{
		path = env_trim(envd[i]);
		fpath = ft_strsplit(path, ':');
		i = sis_exac(envd, argt, fpath);
		free(path);
		mda_clear(fpath);
		return (i);
	}
	return (0);
}

static int		check_for_bi(t_shell *tmp, char **argc)
{
	if (!ft_strcmp(argc[0], "setenv"))
		return (bi_setenv(tmp, argc));
	if (!ft_strcmp(argc[0], "unsetenv"))
		return (bi_unsetenv(tmp, argc));
	if (!ft_strcmp(argc[0], "cd"))
		return (bi_cd(tmp, argc));
	if (!ft_strcmp(argc[0], "echo"))
		return (bi_echo(tmp, argc));
	if (!ft_strcmp(argc[0], "env") || !ft_strcmp(argc[0], "/usr/bin/env"))
		return (bi_env(tmp, argc));
	if (!ft_strcmp(argc[0], "exit"))
		bi_exit();
	return (0);
}

void			exacute(t_shell *tmp, char **argc, char *pt)
{
	struct stat	tt;
	char		**tmpp;

	if (pt == NULL)
		tmpp = tmp->envd;
	else
		tmpp = tmp->envt;
	if (check_for_bi(tmp, argc) || exec_mod(tmpp, argc, pt))
		return ;
	if (lstat(argc[0], &tt) != -1)
	{
		if (tt.st_mode & S_IXUSR)
		{
			to_fork(argc[0], argc, tmpp);
			return ;
		}
	}
	ft_putstr("minishell: command not found: ");
	ft_putendl(argc[0]);
}
