/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:29:42 by dorphan           #+#    #+#             */
/*   Updated: 2019/09/23 11:29:46 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "Libft/libft.h"

static void		ftail(char *buf, char *tail)
{
	char *tmp;

	ft_bzero(tail, BUFF_SIZE + 1);
	tmp = ft_strchr(buf, '\n');
	ft_strcpy(tail, tmp);
	*tmp = '\0';
}

static void		join(char **line, char *buf)
{
	char *copy;

	copy = *line;
	*line = ft_strjoin(copy, buf);
	free(copy);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static char		tail[BUFF_SIZE + 1];

	if (fd < 0)
		return (-1);
	if (!*line)
		*line = malloc(sizeof(*line));
	else
	{
		free(*line);
		*line = ft_strdup(tail);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			ftail(buf, tail);
			join(line, buf);
			return (1);
		}
		join(line, buf);
	}
	return (0);
}
