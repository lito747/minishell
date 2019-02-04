/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:40:22 by mpytienk          #+#    #+#             */
/*   Updated: 2018/03/14 12:40:25 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			cderr(char *path)
{
	ft_putstr("cd: ");
	if (access(path, F_OK) == -1)
		ft_putstr("no such file or directory: ");
	else if (access(path, R_OK) == -1)
		ft_putstr("permission denied: ");
	else
		ft_putstr("not a directory: ");
	ft_putendl(path);
}

static int		comp_bylen(char *s1, char *s2)
{
	int i;
	int k;

	i = ft_strlen(s1);
	k = 0;
	while (s1[k] == s2[k])
		k++;
	if (k == i)
	{
		ft_putchar('~');
		return (k);
	}
	return (0);
}

void			ft_putpwd(t_shell *s, char *pwd)
{
	char	*tmpp;
	char	*tmph;
	int		i;

	if ((i = get_env_pos(s->envd, "HOME")) != -1)
	{
		tmph = env_trim(s->envd[i]);
		tmpp = env_trim(pwd);
		ft_putendl(tmpp + comp_bylen(tmph, tmpp));
		free(tmph);
		free(tmpp);
	}
	else
		ft_putendl("cd: Cannot retrieve HOME path.");
}

char			*path_join(char *path)
{
	char *str;

	if (path[ft_strlen(path) - 1] != '/')
	{
		str = ft_strjoin(path, "/");
		ft_strdel(&path);
		return (str);
	}
	return (path);
}

void			to_fork(char *path, char **argc, char **envd)
{
	pid_t	pid;

	if (!access(path, R_OK || X_OK))
	{
		pid = fork();
		signal(SIGINT, ft_sig_proc);
		if (pid == 0)
			execve(path, argc, envd);
		else if (pid < 0)
		{
			ft_putendl("Fork failed to create process.\n");
		}
		wait(&pid);
	}
	else
	{
		ft_putstr("minishell: Permission denied for : ");
		ft_putendl(path);
	}
}
