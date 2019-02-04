/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:19:41 by mpytienk          #+#    #+#             */
/*   Updated: 2018/03/15 11:19:48 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		cd_unsetenv(t_shell *s, char *arg)
{
	int k;

	if ((k = get_env_pos(s->envt, arg)) != -1)
	{
		ft_strdel(&(s->envt[k]));
		while (s->envt[k + 1])
		{
			s->envt[k] = s->envt[k + 1];
			k++;
		}
		s->envt[k] = NULL;
	}
	else
	{
		ft_putstr("env: ");
		ft_putstr(arg);
		ft_putendl(": no var in ENV");
	}
	return (1);
}

void	print_help(void)
{
	ft_putstr("usage: env: ");
	ft_putstr("-ihu;\n");
	ft_putstr("Name=Value to reset or set variable!\n");
}
