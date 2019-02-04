/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:38:15 by mpytienk          #+#    #+#             */
/*   Updated: 2017/11/01 16:41:03 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int d)
{
	if (s != NULL)
	{
		ft_putstr_fd(s, d);
		ft_putchar_fd('\n', d);
	}
}
