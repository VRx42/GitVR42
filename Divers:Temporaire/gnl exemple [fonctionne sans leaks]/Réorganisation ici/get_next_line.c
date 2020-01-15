/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:53:48 by mikim             #+#    #+#             */
/*   Updated: 2020/01/15 16:52:31 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	r = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (r == NULL)
		return (NULL);
	while (s1[j] != '\0')
		r[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		r[i++] = s2[j++];
	r[i] = '\0';
	return (r);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int		ft_make_new_line(int fd, char **str, char **line, int nbread)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_substr(str[fd], 0, len);
		tmp = ft_strdup(&str[fd][len + 1]);//pareil que s[fd] + len + 1
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);//si on sarrete juste avant le /0 ex; '/n/0'
	}
	else if (str[fd][len] == '\0')//traitement de la derniere ligne
	{
		if (nbread == BUFFER_SIZE)
			return (get_next_line(fd, line));
		//ici on retourne 0 en repassant par gnl parce que si on renvoie 1 alors on va continuer en disant que le fichier nest pas fini alors que cest le cas on est juste tombe pile poil sur le dernier /0
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[1024];//ou alors 1024
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;
	int			nbread;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((nbread = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nbread] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);//malloc+initia a la 1ere iteration quand s[fd] est vide
		tmp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buffer, '\n'))//ici on a colle a la fin le premier buffer contenant \n
			break ;
	}
	if (nbread < 0)//on a rien lu erreur
		return (-1);
	else if (nbread == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);//quand on a fini de lire un fichier ret renvoie 0 sans line. les s[fd] et s[fd][0] ont ete determines dans la boucle juste avant
	return (ft_make_new_line(fd, str, line, nbread));
}

int			main(int ac, char **av)
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
	//get_next_line(fd, &line);
	//printf("[%d] |%s|\n", i,  line);
	close(fd);
	system("leaks a.out");
	return (0);
}
