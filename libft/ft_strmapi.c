/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:51:55 by vronchin          #+#    #+#             */
/*   Updated: 2019/11/22 16:24:27 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*mapped;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	if ((mapped = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mapped[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}
