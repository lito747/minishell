/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:00:46 by mpytienk          #+#    #+#             */
/*   Updated: 2017/12/04 11:00:56 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*ft_findfd(t_list **stlist, int fd)
{
	t_gnl	*tmp;
	t_list	*list;

	list = *stlist;
	while (list)
	{
		tmp = (t_gnl *)list->content;
		if (tmp->fd == fd)
			return (tmp);
		list = list->next;
	}
	tmp = (t_gnl *)ft_memalloc(sizeof(t_gnl));
	tmp->tmp_str = ft_strnew(0);
	tmp->text = NULL;
	tmp->fd = fd;
	list = ft_lstnew(tmp, sizeof(t_gnl));
	ft_memdel((void **)&tmp);
	ft_lstadd(stlist, list);
	return ((t_gnl *)list->content);
}

static int		ft_getres(char *buf_line, char **line)
{
	char	*tmp;

	if (!buf_line)
		return (0);
	tmp = ft_strchr(buf_line, '\n');
	if (tmp)
	{
		*tmp = '\0';
		*line = ft_strdup(buf_line);
		ft_strcpy(buf_line, &tmp[1]);
		return (1);
	}
	else if (ft_strlen(buf_line) > 0)
	{
		*line = ft_strdup(buf_line);
		*buf_line = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*lst;
	t_gnl			*tmp;
	int				ret;

	if (fd == -1 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	tmp = ft_findfd(&lst, fd);
	while (!(ft_strchr(tmp->tmp_str, '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (ft_getres(tmp->tmp_str, line));
		buf[ret] = '\0';
		tmp->text = ft_strjoin(tmp->tmp_str, buf);
		free(tmp->tmp_str);
		tmp->tmp_str = tmp->text;
	}
	return (ft_getres(tmp->text, line));
}
