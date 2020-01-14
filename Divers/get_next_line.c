/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:18:41 by vronchin          #+#    #+#             */
/*   Updated: 2020/01/14 18:08:35 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


int	make_line(char **line,  char **str, char *ptr_str)
{
	size_t		i;
	char		*tmp;

	i = 0;
	while (ptr_str[i] != '\n' && ptr_str[i] != '\0')
		i++;
	if (ptr_str[i] == '\n')
	{
		(*line) = ft_substr(*str, 0, i);//ici on malloc *line, à démalloquer
		//printf("/%c/", *str[0]);
		//printf("/%c/", *str[1]);
		//printf("/%c/", *str[2]);
		//printf("/%c/", *line[3]);
		tmp = ft_strdup(&(*str)[i + 1]);
		free(*str);
		(*str) = tmp;
		if (ptr_str[0] == '\0')
			ft_strdel(&str[
		return (1);
	}
	else//si on a pas trouve de /n alors go back to le fucking \n ou \0 alors on continue dans la boucle
	{
		return (0);
	}
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
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (buffer[0] == '\0')
			return (1);
		tmp = ft_strjoin(str, buffer);//le tmp est malloc
		free(str);
		str = tmp;
		if (make_line(line, &str, str) == 1)//si on trouve dans str un \n ou un \0 on a fini la ligne
		{
			return (1);
		}
	}
	return (make_line(line &str, str));
}

int			main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;
	//int		ret = 0;
	
	i = 1;
	ac = ac + 0;
	fd = open(av[1], O_RDONLY);
	//printf("fd = %d\n", fd);
	while (get_next_line(fd, &line) == 1)
	{
		//get_next_line(fd, &line);
		printf("[%d] |%s|\n", i, line);
		free(line);
		i++;
	}
	//get_next_line(fd, &line);
	//printf("[%d] |%s|\n", i,  line);
	close(fd);
	return (0);
}

/*
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
	return (argc);
}*/
