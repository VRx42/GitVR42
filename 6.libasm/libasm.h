/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 14:48:27 by jnguyen           #+#    #+#             */
/*   Updated: 2020/04/27 14:48:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>

size_t	ft_strlen(const char *str);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strdup(const char *str1);
char	*ft_strcpy(char *src, char *dst);

#endif
