/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:10:54 by vronchin          #+#    #+#             */
/*   Updated: 2020/02/14 14:10:55 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	len_wuchart(unsigned char *str)
{
	size_t a;

	a = 0;
	while (str[a] != 0)
		a++;
	return (a);
}

size_t	len_pstrn(unsigned char *str, size_t len, size_t index)
{
	size_t i;
	size_t a;

	i = 0;
	a = 0;
	if (index == 1)
		len = ft_ustrlen(str) + 1;
	while (str[i] != '\0' && i < len)
	{
		if (ft_isprint(str[i] && str[i] != '\n') || str[i] == '\t')
			a++;
		else
			a += 2;
		i++;
	}
	return (a);
}

void	lst_not_defined(t_format *lst)
{
	if (lst->zero > 1 && lst->point > 1)
		lst->zero = 0;
	else if (lst->zero > 1)
		lst->zero = 1;
	if (lst->point > 1)
	{
		lst->point = 0;
		lst->preci = 0;
	}
	if (lst->conv == 's')
		lst->preci = ft_abs(lst->preci);
	if (lst->space == 1 && (lst->conv == 'x' || lst->conv == 'X'))
		lst->space = 0;
}

void	ftprintf_error(t_format *lst, char *str)
{
	ft_putstr_fd(str, 2);
	if (lst != NULL)
	{
		if (lst->str != NULL)
			free(lst->str);
		free(lst);
	}
	exit(0);
}
