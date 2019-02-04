/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:51:40 by mpytienk          #+#    #+#             */
/*   Updated: 2018/03/14 14:51:42 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_strll(const char *s, char c)
{
	int i;
	int k;

	i = 0;
	k = ft_strlen(s);
	while (i < k)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

static int	key_init(char **arg, int *k)
{
	int i;

	i = 0;
	while (arg[i] && arg[i][0] == '-')
	{
		if (arg[i][1] == 'u')
			*k = 2;
		i++;
	}
	return (i);
}

static int	addor_rem(t_shell *s, char **arg)
{
	int		i;
	int		k;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (arg[i] != NULL && ft_strll(arg[i], '=') != 0)
	{
		tmp = env_get_name(arg[i]);
		if ((k = get_env_pos(s->envt, tmp)) != -1)
			env_replace(s->envt, tmp, ft_strchr(arg[i], '=') + 1);
		if (tmp)
			ft_strdel(&tmp);
		i++;
	}
	return (i);
}

static void	exec_supb(t_shell *s, char **arg, int key_mod)
{
	int i;

	if (*arg && !ft_strcmp(arg[0], "exit"))
		bi_exit();
	if ((i = get_env_pos(s->envd, "PATH")) == -1)
	{
		ft_putstr("env: no $PATH env located!\n");
		return ;
	}
	if (key_mod == 2 && arg[0])
	{
		cd_unsetenv(s, arg[0]);
		arg += 1;
	}
	else if (*arg)
		exacute(s, arg, s->envd[i]);
}

int			bi_env(t_shell *s, char **arg)
{
	int key_mod;

	key_mod = 0;
	if (!arg[1])
		mda_print(s->envd);
	else
	{
		if (!ft_strcmp(arg[1], "-m"))
			mda_print(s->envt);
		s->envt = mda_copy(s->envd);
		arg += 1;
		arg += key_init(arg, &key_mod);
		arg += addor_rem(s, arg);
		exec_supb(s, arg, key_mod);
		mda_clear(s->envt);
	}
	return (1);
}
