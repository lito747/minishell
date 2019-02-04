/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 13:36:18 by mpytienk          #+#    #+#             */
/*   Updated: 2018/02/09 13:36:21 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	display_prompt(void)
{
	ft_putstr("\033[32m");
	ft_putstr("minishel");
	ft_putstr("\033[0m");
	ft_putstr("\033[31m");
	ft_putstr(":> ");
	ft_putstr("\033[0m");
}

int		parse(t_shell *m, char *str)
{
	char	**tmp;
	char	**tmp2;
	int		i;

	i = 0;
	if ((tmp = ft_strsplit(str, ';')) == NULL)
		return (-1);
	mda_trim(tmp);
	while (tmp[i])
	{
		if (is_walidsimbol(tmp[i]))
		{
			tmp2 = ft_newsplit(tmp[i], ' ');
			exacute(m, tmp2, NULL);
			mda_clear(tmp2);
		}
		i++;
	}
	mda_clear(tmp);
	return (0);
}
