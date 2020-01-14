/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:53:48 by mikim             #+#    #+#             */
/*   Updated: 2020/01/14 23:15:17 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_new_line(char **s, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(&s[fd][len + 1]);//pareil que s[fd] + len + 1
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);//si on sarrete juste avant le /0 ex; '/n/0'
	}
	else if (s[fd][len] == '\0')//traitement de la derniere ligne 
	{ 
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		//ici on retourne 0 en repassant par gnl parce que si on renvoie 1 alors on va continuer en disant que le fichier nest pas fini alors que cest le cas on est juste tombe pile poil sur le dernier /0
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[255];//ou alors 1024
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);//malloc+initia a la 1ere iteration quand s[fd] est vide
		printf("*%s*\n", s[fd]);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))//ici on a colle a la fin le premier buffer contenant \n
			break ;
	}
	if (ret < 0)//on a rien lu erreur
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);//quand on q fini de lire un fichier ret renvoie 0 sans line. les s[fd] et s[fd][0] ont ete determines dans la boucle juste avant 
	return (ft_new_line(s, line, fd, ret));
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
