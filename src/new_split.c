/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:39:10 by mpytienk          #+#    #+#             */
/*   Updated: 2018/03/05 10:39:13 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static size_t	ft_skip(const char *s, char c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

static size_t	ft_wcount(char *s, char c)
{
	size_t	qword;
	int		flag;
	char	m;

	qword = 0;
	flag = 0;
	while (*s)
	{
		if (flag == 1 && *s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			if (*s == '\"' || *s == '\'')
			{
				m = *s;
				s++;
				s += ft_skip(s, m);
			}
			flag = 1;
			qword++;
		}
		s++;
	}
	return (qword);
}

static size_t	ft_subl(char const *s, char c)
{
	size_t	len;
	size_t	tmp;
	char	m;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		if (*s == '\"' || *s == '\'')
		{
			len++;
			m = *s;
			s++;
			tmp = ft_skip(s, m);
			len += tmp;
			s += tmp;
		}
		if (*s != '\0')
		{
			len++;
			s++;
		}
	}
	return (len);
}

static int		ft_resfree(char **res, size_t i)
{
	size_t k;

	k = 0;
	if (res[i] == NULL)
	{
		while (k < i)
		{
			free(res[k]);
			res[k] = NULL;
			k++;
		}
		ft_strdel(res);
		return (1);
	}
	return (0);
}

char			**ft_newsplit(char const *s, char c)
{
	size_t	i;
	size_t	qword;
	char	**res;

	if (s == NULL)
		return (NULL);
	i = 0;
	qword = ft_wcount((char *)s, c);
	res = (char**)malloc(sizeof(char*) * (qword + 1));
	if (res == NULL)
		return (NULL);
	while (qword)
	{
		while (*s != '\0' && *s == c)
			s++;
		res[i] = ft_strsub(s, 0, ft_subl((char *)s, c));
		if (ft_resfree(res, i))
			return (NULL);
		s += ft_subl((char *)s, c);
		i++;
		qword--;
	}
	res[i] = NULL;
	return (res);
}
