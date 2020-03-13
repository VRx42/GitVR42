/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:39:58 by vronchin          #+#    #+#             */
/*   Updated: 2019/11/22 15:40:00 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	my_c;
	size_t			i;

	s1 = (unsigned char*)s;
	my_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == my_c)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
