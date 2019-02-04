/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:15:08 by mpytienk          #+#    #+#             */
/*   Updated: 2018/02/12 13:15:11 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		get_env_pos(char **env, char *str)
{
	int	i;
	int	k;

	i = 0;
	while (env[i])
	{
		k = 0;
		while (env[i][k] == str[k])
		{
			k++;
			if (env[i][k] == '=')
				return (i);
		}
		i++;
	}
	return (-1);
}

char	*env_get_name(char *str)
{
	int		tmp;
	char	*tmpc;

	tmp = 0;
	tmpc = ft_strnew(ft_strlen(str));
	while (str[tmp] != '=')
		tmp++;
	ft_strncpy(tmpc, str, tmp);
	return (tmpc);
}

char	*env_trim(char *str)
{
	char *tmp;

	while (*str != '=')
		str++;
	str++;
	tmp = ft_strdup(str);
	return (tmp);
}

char	*env_combine(char *s1, char *s2)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strjoin(s1, "=");
	tmp2 = ft_strjoin(tmp, s2);
	ft_strdel(&tmp);
	return (tmp2);
}

void	env_replace(char **env, char *s1, char *s2)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp = env_combine(s1, s2);
	if ((i = get_env_pos(env, s1)) != -1)
	{
		tmp2 = env[i];
		env[i] = tmp;
		ft_strdel(&tmp2);
	}
	else
		ft_strdel(&tmp);
}
