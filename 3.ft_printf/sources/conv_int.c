/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:10:54 by vronchin          #+#    #+#             */
/*   Updated: 2020/02/14 14:10:55 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_int(t_format *lst)
{
	int len;
	int max;

	lst_putint(lst);
	len = unsigned_len_base(lst->ul_nb, lst->base);
	if (lst->ul_nb == 0 && lst->point == 1 && lst->preci == 0)
		len = 0;
	ft_space_count(lst, len);
	max = ft_max(len, lst->preci) + ft_strlen(lst->presign);
	if (lst->zero == 1)
		put_buff(lst, lst->presign, ft_strlen(lst->presign), 0);
	put_prefix_buff(lst, max + lst->hash, lst->field, lst->zero);
	if (lst->zero == 0)
		put_buff(lst, lst->presign, ft_strlen(lst->presign), 0);
	put_prefix_buff(lst, 0, lst->hash, 1);
	put_prefix_buff(lst, len, lst->preci, 1);
	if (!(lst->point == 1 && lst->preci == 0 && lst->ul_nb == 0))
		put_itoa(lst, lst->ul_nb);
	put_prefix_buff(lst, max, -lst->field, 0);
}

void	lst_putint(t_format *lst)
{
	if (lst->conv == 'd' || lst->conv == 'i')
		lst_putnb_signed_nb(lst);
	else
		lst_putnb_unsigned_nb(lst);
	if (lst->conv == 'p')
		lst->presign = (lst->maj == 1 ? "0X" : "0x");
}

void	lst_putnb_signed_nb(t_format *lst)
{
	long nb_tmp;

	nb_tmp = va_arg(lst->va_copy, int);
	lst->presign = (nb_tmp < 0 ? "-" : "");
	if (lst->sign == '+' && nb_tmp >= 0 && (lst->conv == 'd'
	|| lst->conv == 'i'))
		lst->presign = "+";
	lst->ul_nb = (nb_tmp < 0 ? -nb_tmp : nb_tmp);
}

void	lst_putnb_unsigned_nb(t_format *lst)
{
	if (lst->conv == 'x' || lst->conv == 'X' || lst->conv == 'u')
		lst->ul_nb = va_arg(lst->va_copy, unsigned int);
	else
	{
		lst->ul_nb = va_arg(lst->va_copy, unsigned long);
	}
	if (lst->sign == '+' && (lst->conv == 'd' || lst->conv == 'i'))
		lst->presign = "+";
}

int		unsigned_len_base(unsigned long nb, size_t base)
{
	if (nb < base)
		return (1);
	else
	{
		nb = (nb / base);
		return (unsigned_len_base(nb, base) + 1);
	}
}
