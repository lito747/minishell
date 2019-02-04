/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:37:58 by mpytienk          #+#    #+#             */
/*   Updated: 2018/02/14 14:38:01 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**mda_alloc(int size)
{
	int		i;
	char	**tm;

	i = 0;
	tm = (char**)malloc(sizeof(char *) * size);
	while (i < size)
	{
		tm[i] = NULL;
		i++;
	}
	return (tm);
}

void	mod_env(t_shell *tmp, char *str)
{
	int		i;
	int		k;
	char	**tm;

	i = mda_len(tmp->envd) + 1;
	tm = mda_alloc(i + 1);
	k = 0;
	while (tmp->envd[k])
	{
		tm[k] = ft_strdup(tmp->envd[k]);
		k++;
	}
	tm[k] = ft_strdup(str);
	mda_clear(tmp->envd);
	tmp->envd = tm;
}

int		bi_setenv(t_shell *tmp, char **arg)
{
	char	*tm;
	int		i;

	if (arg[1] && arg[2] && mda_len(arg) == 3)
	{
		if ((i = get_env_pos(tmp->envd, arg[1])) != -1)
			env_replace(tmp->envd, arg[1], arg[2]);
		else
		{
			tm = env_combine(arg[1], arg[2]);
			mod_env(tmp, tm);
			ft_strdel(&tm);
		}
	}
	else
	{
		ft_putendl("setenv: usage: str1 = VAR_NAME, str2 = VAR_CONTENT\n");
	}
	return (1);
}
