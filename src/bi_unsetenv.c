/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:38:17 by mpytienk          #+#    #+#             */
/*   Updated: 2018/02/14 14:38:19 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	bi_unsetenv(t_shell *s, char **arg)
{
	int i;
	int k;

	i = 1;
	while (arg[i])
	{
		if ((k = get_env_pos(s->envd, arg[i])) != -1)
		{
			ft_strdel(&(s->envd[k]));
			while (s->envd[k + 1])
			{
				s->envd[k] = s->envd[k + 1];
				k++;
			}
			s->envd[k] = NULL;
		}
		else
		{
			ft_putstr("unsetenv: ");
			ft_putstr(arg[i]);
			ft_putendl(": no var in ENV");
		}
		i++;
	}
	return (1);
}
