/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:18:41 by vronchin          #+#    #+#             */
/*   Updated: 2019/11/29 17:15:42 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


int	make_line(char **line,  char *str)
{
	size_t		i;
	char		*tmp;

	printf("2");
	if (ft_strchr(str, '\n') == NULL)//si on a pas de \n alors retourne 0 et apres read un autre buffer dans gnl
		return (0);// on retourne 0 donc dans le gnl on refait une boucle en gardant dans le static str qvec le debut sans /n
	else//si on trouve un \n alors go modifier la line et retourner 1 en joingant le str
	{
		i = 0;
		while (str[i] != '\n')
			i++;
		tmp = str;// str et tmp pointent vers les memes adresses donc on peut free tmp
		*line = ft_substr(tmp, 0, i + 1);//si on a un  /n alors on met dans le line str jsqu a i. OK pour line, modifiee a distance et malloke
		str = ft_substr(tmp, i + 1, ft_strlen(str) - (i + 1) + 1); //ici on veut un str qui commence apres i + 1 mais on doit copier sur tmp avant
		//free(tmp);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 2];
	static char	*str;

	str = NULL;
	printf("0.8");
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	printf("0.9");
	while (read(fd, buffer, BUFFER_SIZE) > 0)//tant que read > 0 (i.e qu' on a lu quelque chose)
	{
		buffer[BUFFER_SIZE + 1] = '\0';
		if (buffer[0] == '\0')
			return (1);
		printf("1");
		str = ft_strjoin(str, buffer);//le strjoin free aussi le str entrant donc pas besoin de tmp
		if (make_line(line, str) == 1)//si pas un alors pas de /n et on refait une lecture pour avoir un /n
			return (1);
	}
	return (0);
}

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
	while (get_next_line(fd, &line) && i < 10)
	{
		ret = get_next_line(fd, &line);
		printf("[%d] [%d] |%s|\n", i++, ret,  line);
		free(line);
	}
	close(fd);
	return (0);
}


/*
int	main()
{
	int			ret = 0;
	char		*line;
//	char		*ptr_char;
	int			fd;

	//ft_strdup(ptr_char);
	line = NULL;
	//fd = 1;
	printf("****\n");
	fd = open("~/Documents/2.Cursus_C_42/get_next_line/toto.txt", O_RDONLY);
	printf("%d\n", fd);
	printf("****\n");
	close(fd);
	printf("***********");
	ret = 1;// get_next_line(fd, &line);
	printf("%d - %s", ret, line);

	puts(line);

	return 0;
}*/

/*
int	main(int argc, char const *argv[])
{
	int fd;
	int fd_2;
	int i;
	char *line;
	int status;
	
	fd = open(argv[1], O_RDONLY);
	printf("fd = %d", fd);
	i = 1;
	while ((status = get_next_line(fd, &line)) == 1 && i < 500)
	{
		printf("[%d] %s\n", i++, line);
		free(line);
	}
	fd_2 = open(argv[2], O_RDONLY);
	close(fd);
	fd = fd_2;
	while ((status = get_next_line(fd, &line)) == 1)
	{
		printf("[%d] %s\n", i++, line);
		free(line);
	}
	return (argc);
}*/
