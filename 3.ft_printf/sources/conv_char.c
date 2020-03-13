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

void	conv_char(t_format *lst)
{
	size_t	verif;

	if (lst->conv != 'c' && lst->conv != 'C')
		pf_putchar(lst, lst->conv, 0, 0);
	else
	{
		verif = va_arg(lst->va_copy, int);
		pf_putchar(lst, (char)verif, 0, 0);
	}
}

void	pf_putchar(t_format *lst, unsigned char c, unsigned char *wc, int index)
{
	size_t max;

	if (index == 1)
		max = len_wuchart(wc);
	else
		max = 1;
	put_prefix_buff(lst, max, lst->field, lst->zero);
	put_buff(lst, (index == 1 ? wc : &c), max, index);
	put_prefix_buff(lst, max, -lst->field, 0);
}
