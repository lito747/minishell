/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:29:05 by mpytienk          #+#    #+#             */
/*   Updated: 2018/03/05 13:29:07 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_sig_int(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		display_prompt();
	}
}

void	ft_sig_proc(int sig)
{
	if (sig == SIGINT)
		ft_putchar('\n');
}

void	sig_try(void)
{
	signal(SIGINT, ft_sig_int);
}
