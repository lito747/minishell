/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 10:32:09 by mpytienk          #+#    #+#             */
/*   Updated: 2018/03/14 10:32:11 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	epprint_sup(char *s, char *tmp, int flag)
{
	char *ptmp;

	ptmp = env_get_name(s);
	if (ft_strlen(ptmp) == (ft_strlen(tmp) - flag))
	{
		free(ptmp);
		ptmp = env_trim(s);
		ft_putstr(ptmp);
		free(ptmp);
	}
	else
		free(ptmp);
}

char	*solv_home(t_shell *st, char *s)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	if ((i = get_env_pos(st->envd, "HOME")) > -1)
	{
		tmp = st->envd[i];
		tmp2 = env_trim(tmp);
		tmp = ft_strjoin(tmp2, s + 1);
		free(tmp2);
		return (tmp);
	}
	else
		ft_putendl("$HOME does not exist!");
	return (NULL);
}

int		is_qoted(char *s)
{
	int i;

	i = ft_strlen(s);
	if (s[0] == '\'' && s[i - 1] == '\'')
		return (2);
	if (s[0] == '\"' && s[i - 1] == '\"')
		return (1);
	return (0);
}

int		is_space(char c)
{
	if ((c == '\n') || (c == '\t') || (c == '\v') ||
		(c == ' ') || (c == '\f') || (c == '\r'))
		return (1);
	return (0);
}

void	path_change(t_shell *s, char *path, int i, int k)
{
	char *tmp;
	char *tmp2;

	tmp = s->envd[i];
	tmp2 = env_trim(s->envd[k]);
	s->envd[i] = env_combine("OLDPWD", tmp2);
	free(tmp);
	free(tmp2);
	tmp = s->envd[k];
	s->envd[k] = env_combine("PWD", path);
	free(tmp);
}
