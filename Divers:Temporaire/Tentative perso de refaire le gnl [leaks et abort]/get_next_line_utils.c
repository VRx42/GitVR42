/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:57:52 by vronchin          #+#    #+#             */
/*   Updated: 2020/01/15 17:00:16 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *as)
{
	size_t	i;

	i = 0;
	while (as[i])
		i++;
	return (i);
}

void	ft_strdel(char **as)
{
	if (as)
	{
		free (*as);
		*as = NULL;
	}
	return ;
}

char	*ft_strnew(size_t  size)
{
	size_t	i;
	char	*s;

	s = (char*)malloc(size + 1);
	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < size)
		s[i++] = 0;
	s[size] = '\0';
	return (s);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char*)malloc(sizeof(*s2) * (i + 1));
	if (s2 == NULL)
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char *as,size_t start, size_t len)
{
	char	*res;
	size_t	j;

	j = 0;
	if (as == NULL)
		return (NULL);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (j < len)
	{
		res[j] = as[start + j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return(NULL);
	res = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i]= '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	while (*s)
	{
		if (*s == c)
		{
			tmp = (char*)s;
			return (tmp);
		}
		s++;
	}
	if (c == '\0')
	{
		tmp = (char*)s;
		return (tmp);
	}
	return (NULL);
}
