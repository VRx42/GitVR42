/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:44:48 by vronchin          #+#    #+#             */
/*   Updated: 2019/11/22 15:45:01 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	my_c;

	i = 0;
	my_c = (const char)c;
	while (s[i])
	{
		if (s[i] == my_c)
			return ((char*)&s[i]);
		i++;
	}
	if (s[i] == my_c)
		return ((char*)&s[i]);
	return (NULL);
}
