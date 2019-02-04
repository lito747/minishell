/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:19:32 by mpytienk          #+#    #+#             */
/*   Updated: 2018/02/08 15:19:36 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			is_walidsimbol(char *l)
{
	int i;

	i = 0;
	while (l[i])
	{
		if (ft_isprint(l[i]) && l[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

static int	is_spcheck(char *l)
{
	int i;

	i = 0;
	while (l[i])
	{
		if (ft_isprint(l[i]) && l[i] != ';')
			return (1);
		i++;
	}
	return (0);
}

static void	clear_tabs(char *l)
{
	int i;

	i = 0;
	while (l[i])
	{
		if (l[i] == '\t')
			l[i] = ' ';
		i++;
	}
}

static void	main_loop(t_shell *tmp)
{
	char	*line;

	(void)tmp;
	while (42)
	{
		sig_try();
		display_prompt();
		get_next_line(0, &line);
		if (is_walidsimbol(line) && is_spcheck(line))
		{
			clear_tabs(line);
			parse(tmp, line);
		}
		ft_strdel(&line);
	}
}

int			main(int argc, char **argv, char **env)
{
	t_shell	tmp;
	char	tpath[PATH_MAX + 1];

	(void)argc;
	(void)argv;
	tmp.envd = mda_copy(env);
	getcwd(tpath, PATH_MAX + 1);
	env_replace(tmp.envd, "PWD", tpath);
	env_replace(tmp.envd, "OLDPWD", tpath);
	main_loop(&tmp);
	mda_clear(tmp.envd);
	return (0);
}
