/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:18:41 by vronchin          #+#    #+#             */
/*   Updated: 2019/12/04 12:04:24 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


int	make_line(char **line,  char **str, char *ptr_str)
{
	size_t		i;
	char		*tmp;

	//printf("2")
	i = 0;
	while (ptr_str[i] != '\n' && ptr_str[i])
		i++;
	//printf("= %c =", ptr_str[i]);
	if (ptr_str[i] == '\n')
	{
		(*line) = ft_substr(*str, 0, i);
		//puts((*line));
		tmp = ft_strdup(&(*str)[i + 1]);
		puts(tmp);
		free(*str);
		(*str) = tmp;
		//puts((*str));
	}
	//else
	//{
	//	(*line) = ft_strdup(*str);
	//	puts((*line));
	//}	
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*str;
	int 		ret;
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 0)
		return (-1);
	if (!str)
	{
		if (!(str = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	}
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)//tant que read > 0 (i.e qu' on a lu quelque chose)
	{
		buffer[ret] = '\0';
		if (buffer[0] == '\0')
			return (1);
		tmp = ft_strjoin(str, buffer);
		str = tmp;
		//printf("*");
		//puts(str);
		//printf("*");
		if (make_line(line, &str, str) == 1)//deux cqs; on a un \n ou pas
			return (1);
	}
	return (0);
}
/*
int			main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;
	int		ret = 0;
	
	i = 1;
	ac = ac + 0;
	fd = open(av[1], O_RDONLY);
	//printf("fd = %d\n", fd);
	while ((get_next_line(fd, &line) == 1))
	{
		ret = get_next_line(fd, &line);
		//printf("[%d] [%d] |%s|\n", i, ret,  line);
		//printf("%d - \n", i);
		i++;
		free(line);
	}
	close(fd);
	return (0);
}*/


int	main(int argc, char const *argv[])
{
	int fd;
	//int fd_2;
	int i;
	char *line;
	int status;
	
	fd = open(argv[1], O_RDONLY);
	//printf("fd = %d", fd);
	i = 1;
	while ((status = get_next_line(fd, &line)) == 1 && i < 500)
	{
		printf("[%d] %s\n", i++, line);
		free(line);
	}
	/*fd_2 = open(argv[2], O_RDONLY);
	close(fd);
	fd = fd_2;
	while ((status = get_next_line(fd, &line)) == 1)
	{
		printf("[%d] %s\n", i++, line);
		free(line);
	}*/
	return (argc);
}
