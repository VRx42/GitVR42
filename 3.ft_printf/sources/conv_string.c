/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:10:54 by vronchin          #+#    #+#             */
/*   Updated: 2020/02/14 14:10:55 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				conv_string(t_format *lst)
{
	unsigned char	*ustr;

	ustr = (unsigned char*)va_arg(lst->va_copy, char*);
	if (ustr == NULL)
		ustr = ft_strudup("(null)");
	else
		ustr = ft_ustrdup(ustr);
	pf_string(lst, ustr, 1);
}

void				pf_string(t_format *lst, unsigned char *str, int index)
{
	size_t	max;

	max = 0;
	if (index == 0)
		if (lst->point == 0)
			max = len_pstrn(str, 0, 1);
		else
			len_pstrn(str, lst->preci, 0);
	else if (index == 1)
		max = (lst->point == 0 ? ft_ustrlen(str) :
		ft_ustrnlen(str, lst->preci));
	put_prefix_buff(lst, max, lst->field, lst->zero);
	put_buff(lst, str, max, 1);
	put_prefix_buff(lst, max, -lst->field, 0);
}

unsigned char		*ft_ustrdup(unsigned char *s1)
{
	unsigned char	*dest;
	int				len;
	int				count;

	len = ft_ustrlen(s1);
	count = 0;
	if (!(dest = (unsigned char *)malloc(sizeof(unsigned char) * len + 1)))
		return (NULL);
	while (s1[count] != '\0')
	{
		dest[count] = s1[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

unsigned char		*ft_strudup(char *s1)
{
	unsigned char	*dest;
	int				len;
	int				count;

	len = ft_strlen(s1);
	count = 0;
	if (!(dest = (unsigned char *)malloc(sizeof(unsigned char) * len + 1)))
		return (NULL);
	while (s1[count] != '\0')
	{
		dest[count] = s1[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
