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
#include <stdio.h>

int 	is_n(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		printf("\\n detected! i = %d\n", i);
		return (i);
	}
	else
		return (0);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char tail[BUFF_SIZE + 1];
	char 		head[BUFF_SIZE + 1];
	char 		*str;
	int			ret;

	if (!line || fd < 0)
		return (-1);
	str = malloc(1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{

		buf[ret] = '\0';
		printf("str is: %s\n", str);
		printf("buf is: %s\n", buf);
		printf("%d\n", is_n(buf));
		if (!(is_n(buf)))
			str = ft_strjoin(str, buf);
		else if (is_n(buf))
		{
			ft_strcpy(tail, &buf[is_n(buf)]);
			printf("tail is %s\n", tail);
			ft_strncpy(head, buf, is_n(buf));
			str = ft_strjoin(str, head);
			*line = str;
			return (1);
		}
		printf("***************************************************************************\n");
		printf("buf is: %s\n", buf);
		printf("===========================================================================\n");
		printf("str is: %s\n", str);
		printf("***************************************************************************\n");
	}
	*line = str;
	return (0);
}