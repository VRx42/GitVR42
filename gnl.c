#include "get_next_line.h"
#include <stdio.h>

int		checkerror(int fd, char **str, char **line)
{
	if (fd == -1 || line == NULL)
		return (-1);
	if (!*str)
	{
		if (!(*str = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	}
	return (0);
}

char	*readline(char *str, int fd)
{
	char		buff[BUFFER_SIZE + 1];
	int			ret;

	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int		get_next_line(int const fd, char **line)
{
	static char	*str;
	int			i;

	if (checkerror(fd, &str, line) == -1)
		return (-1);
	if (*str)
		ft_strcpy(*line, str);
	str = readline(str, fd);
	i = 0;
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (i == 0)
			(*line) = ft_strdup("");
		else
		{
			(*line) = ft_strsub(str, 0, i);
			str = &str[i + 1];
		}
		return (1);
	}
	else
		(*line) = ft_strdup("");
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