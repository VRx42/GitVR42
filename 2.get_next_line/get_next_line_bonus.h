/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:04:13 by vronchin          #+#    #+#             */
/*   Updated: 2020/02/14 14:03:16 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
int		ft_make_new_line(int fd, char **line, char **str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *as);
char	*ft_strdup(char *s1);
char	*ft_substr(char *as, size_t start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	ft_freee(char **s);

#endif
