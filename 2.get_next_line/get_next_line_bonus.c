/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:01:23 by vronchin          #+#    #+#             */
/*   Updated: 2020/02/16 10:23:41 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_freee(char **s)
{
	if (s)
	{
		free(*s);
		*s = NULL;
	}
	return ;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	res = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	while (s1[j] != '\0')
		res[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
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

int		get_next_line(int fd, char **line)
{
	static char	*str[1024];
	char		*buffer;
	char		*tmp;
	int			nbread;

	if (!(buffer = (char *)malloc(BUFFER_SIZE + 1)) || line == NULL
	|| fd < 0 || read(fd, buffer, 0) || BUFFER_SIZE < 1)
		return (-1);
	while ((nbread = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nbread] = '\0';
		str[fd] == NULL ? str[fd] = ft_strdup("") : (void)str;
		tmp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (nbread == 0 && str[fd] == NULL)
	{
		(*line) = ft_strdup("");
		return (0);
	}
	return (ft_make_new_line(fd, str, line));
}

int		ft_make_new_line(int fd, char **str, char **line)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_substr(str[fd], 0, len);
		tmp = ft_strdup(&str[fd][len + 1]);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_freee(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_freee(&str[fd]);
		return (0);
	}
	return (1);
}
