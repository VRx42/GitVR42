/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:04:13 by vronchin          #+#    #+#             */
/*   Updated: 2020/01/15 16:29:03 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 32
int		get_next_line(int fd, char **line);
int		ft_make_new_line(int fd, char **line, char **str, int nbread);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *as);
char	*ft_strdup(char *s1);
char	*ft_substr(char *as, size_t start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnew(size_t size);
void	ft_strdel(char **s);

#endif
