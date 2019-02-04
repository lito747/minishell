/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:13:50 by mpytienk          #+#    #+#             */
/*   Updated: 2018/03/12 11:13:52 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	new_dir(t_shell *s, char *path, int flag)
{
	char	*c_path;
	int		i;
	int		k;
	int		p;
	char	buff[PATH_MAX];

	c_path = getcwd(buff, PATH_MAX);
	if ((p = chdir(path)) != -1)
	{
		i = get_env_pos(s->envd, "OLDPWD");
		if (flag == 1 && i != -1)
			ft_putpwd(s, s->envd[i]);
		k = get_env_pos(s->envd, "PWD");
		if (i != -1 && k != -1)
			path_change(s, path, i, k);
		else
			ft_putendl("cd: Cannot retrieve OLDPWD or PWD path.");
	}
	else
		cderr(path);
}

static int	cd_norm2(t_shell *s)
{
	char	*tmp;
	int		i;

	if ((i = get_env_pos(s->envd, "OLDPWD")) != -1)
	{
		tmp = env_trim(s->envd[i]);
		new_dir(s, tmp, 1);
		free(tmp);
		return (1);
	}
	else
		ft_putendl("cd: Cannot retrieve OLDPWD path.");
	return (1);
}

static void	cd_norm(t_shell *s, char **arg, char *home)
{
	char *tmp;

	if (arg[2])
	{
		ft_putendl("cd: too many arguments");
		return ;
	}
	if (ft_strequ(arg[1], "--") || arg[1][0] == '~')
	{
		if (home == NULL)
			ft_putendl("cd: Cannot retrieve HOME path.");
		else if (arg[1][0] == '~')
		{
			tmp = solv_home(s, arg[1]);
			new_dir(s, tmp, 0);
			free(tmp);
		}
		else
			new_dir(s, home, 0);
	}
	else if (ft_strequ(arg[1], "-"))
		cd_norm2(s);
	else
		new_dir(s, arg[1], 0);
}

int			bi_cd(t_shell *s, char **arg)
{
	int		i;
	char	*tmp;

	i = 0;
	if ((i = get_env_pos(s->envd, "HOME")) != -1)
		tmp = env_trim(s->envd[i]);
	else
	{
		ft_putendl("cd: Cannot retrieve HOME path.");
		return (1);
	}
	if (!arg[1])
	{
		new_dir(s, tmp, 0);
		free(tmp);
		return (1);
	}
	cd_norm(s, arg, tmp);
	free(tmp);
	return (1);
}
