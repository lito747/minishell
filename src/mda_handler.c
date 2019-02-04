/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mda_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:21:58 by mpytienk          #+#    #+#             */
/*   Updated: 2018/02/08 15:22:04 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	mda_clear(char **arr)
{
	int i;

	i = 0;
	if (arr != NULL && *arr != NULL)
	{
		while (arr[i])
		{
			ft_memdel((void *)&arr[i]);
			i++;
		}
		ft_memdel((void *)&arr);
	}
}

void	mda_trim(char **arr)
{
	int		i;
	char	*tmp;

	i = 0;
	if (arr != NULL && *arr != NULL)
	{
		while (arr[i])
		{
			tmp = arr[i];
			arr[i] = ft_strtrim(tmp);
			ft_strdel(&tmp);
			i++;
		}
	}
}

int		mda_len(char **arr)
{
	int i;

	i = 0;
	if (arr != NULL && *arr != NULL)
	{
		while (arr[i])
			i++;
	}
	return (i);
}

void	mda_print(char **arr)
{
	int i;

	i = 0;
	if (arr != NULL && *arr != NULL)
	{
		while (arr[i])
		{
			ft_putendl(arr[i]);
			i++;
		}
	}
}

char	**mda_copy(char **arr)
{
	char	**dup;
	int		i;

	i = 0;
	if (arr != NULL && *arr != NULL)
	{
		dup = (char **)ft_memalloc(sizeof(char *) * (mda_len(arr) + 1));
		if (dup)
		{
			while (arr[i])
			{
				dup[i] = ft_strdup(arr[i]);
				i++;
			}
			dup[i] = NULL;
			return (dup);
		}
		return (NULL);
	}
	return (NULL);
}
