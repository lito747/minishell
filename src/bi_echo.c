/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:02:01 by mpytienk          #+#    #+#             */
/*   Updated: 2018/03/13 11:02:04 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	epprint(t_shell *st, char *s, int flag)
{
	int		k;
	int		i;
	char	*tmp;

	k = 0;
	while (!is_space(s[k]) && s[k] != '\0')
		k++;
	tmp = ft_strnew(k + 1);
	ft_strncpy(tmp, s + 1, k);
	if ((i = get_env_pos(st->envd, tmp)) != -1)
	{
		epprint_sup(st->envd[i], tmp, flag);
		free(tmp);
		return (k);
	}
	free(tmp);
	ft_putchar(' ');
	return (k);
}

static void	qprint(t_shell *st, char *s, int flag)
{
	int i;
	int k;

	k = ft_strlen(s) - 1;
	i = 1;
	while (i < k)
	{
		if (s[i] == '$' && flag == 1)
			i += epprint(st, s + i, 1);
		ft_putchar(s[i]);
		i++;
	}
}

static void	nqprint(t_shell *st, char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (s[i] == '~')
		tmp = solv_home(st, s);
	if (tmp != NULL)
		s = tmp;
	while (s[i])
	{
		if (s[i] == '$')
			i += epprint(st, s + i, 0);
		ft_putchar(s[i]);
		i++;
	}
	if (tmp != NULL)
		free(tmp);
}

static void	echo_loop(t_shell *st, char **arg, int flag, int i)
{
	int tmp;

	while (arg[i])
	{
		if ((tmp = is_qoted(arg[i])) > 0)
			qprint(st, arg[i], tmp);
		else
			nqprint(st, arg[i]);
		if (flag == 1 && arg[i + 1])
			ft_putchar('\n');
		if (arg[i + 1] && flag != 1)
			ft_putchar(' ');
		i++;
	}
}

int			bi_echo(t_shell *st, char **arg)
{
	int i;
	int flag;

	i = 1;
	flag = 0;
	if (!arg[1])
	{
		ft_putchar('\n');
		return (1);
	}
	if (arg[1] && ft_strequ(arg[1], "-n"))
	{
		i++;
		flag = 1;
	}
	echo_loop(st, arg, flag, i);
	ft_putchar('\n');
	return (1);
}
