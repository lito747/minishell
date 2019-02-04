/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:00:45 by mpytienk          #+#    #+#             */
/*   Updated: 2018/02/02 14:20:59 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 42

typedef struct		s_gnl
{
	char			*text;
	char			*tmp_str;
	int				fd;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
