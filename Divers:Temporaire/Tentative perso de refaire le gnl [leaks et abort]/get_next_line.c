/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:53:48 by vronchin          #+#    #+#             */
/*   Updated: 2020/01/15 17:12:30 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_make_line(char **line, char **str, int fd, int ret)
{
	int		len;
	char	*tmp;

	len = 0;
	while (str[fd][len] != '\0' && str[fd][len] != '\n')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_substr(str[fd], 0, len);
		tmp = ft_strdup(&str[fd][len + 1]);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (ret == BUFFER_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int		ret;
	char	*str[255];
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str[fd] == NULL)
			 str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd] == '\0' || str[fd] == NULL))
		return (0);
	return (ft_make_line(line, str, fd, ret));
}



int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	ac = ac + 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("[%d] |%s|\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return 0;
}
