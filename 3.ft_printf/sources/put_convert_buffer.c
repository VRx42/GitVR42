/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_convert_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:10:54 by vronchin          #+#    #+#             */
/*   Updated: 2020/02/14 14:10:55 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_buff(t_format *lst, void *tmp, size_t len, size_t index)
{
	if (len == 0)
		return ;
	if (((lst->buff_count + len) >= BUFF_PRINTF) || len >= BUFF_PRINTF)
		convert_buff(lst, tmp, len);
	else
	{
		ft_memcpy(lst->buff + lst->buff_count, tmp, len);
		lst->buff_count += len;
	}
	if (index == 1)
		free(tmp);
}

void	put_prefix_buff(t_format *lst, int len, int nb, int point)
{
	size_t			len2;
	unsigned char	*tmp[nb - len];

	len2 = (nb - len);
	if (len >= nb)
		return ;
	if ((len2 + lst->buff_count) >= BUFF_PRINTF)
	{
		ft_memset(tmp, (point == 1 ? '0' : ' '), len2);
		convert_buff(lst, tmp, len2);
	}
	else
	{
		ft_memset(lst->buff + lst->buff_count, (point == 1 ? '0' : ' '), len2);
		lst->buff_count += len2;
	}
}

void	convert_buff(t_format *lst, void *tmp, size_t len)
{
	unsigned char	*new;
	size_t			len_malloc;

	len_malloc = lst->count + lst->buff_count + len + 1;
	if ((new = (unsigned char*)ft_memalloc(len_malloc)) == NULL)
		ERROR(lst, "MALLOC:convert_buff_error");
	new[lst->count + lst->buff_count + len + 1] = '\0';
	ft_memcpy(new, lst->str, lst->count);
	ft_memcpy(new + lst->count, lst->buff, lst->buff_count);
	if (len > 0)
		ft_memcpy(new + lst->count + lst->buff_count, tmp, len);
	if (lst->str != NULL)
		free(lst->str);
	lst->str = new;
	lst->count += lst->buff_count + len;
	lst->buff_count = 0;
}

void	ft_space_count(t_format *lst, int len)
{
	if ((lst->hash == 1 && (lst->conv == 'o' || lst->conv == 'O')) &&
		!((lst->ul_nb == 0 && lst->point == 1 && lst->preci > 0) ||
			(lst->point == 0 && lst->ul_nb == 0)))
	{
		lst->hash = 1;
		if ((lst->point == 1 && lst->preci > len))
			lst->preci = (lst->preci != 0 ? lst->preci - 1 : lst->preci);
		if (lst->field < 0)
			lst->field++;
	}
	else
		lst->hash = 0;
	if (lst->point == 1 && lst->preci >= 0)
		lst->zero = 0;
	if (lst->space == 1 && lst->sign != '+' && ft_strlen(lst->presign) == 0
			&& lst->conv != 'u' && lst->conv != 'U')
	{
		put_prefix_buff(lst, 0, 1, 0);
		if (lst->field > 0)
			lst->field--;
		else if (lst->field < 0)
			lst->field++;
	}
}

void	put_itoa(t_format *lst, unsigned long n)
{
	unsigned char	tmp[27];
	int				len;
	int				mlen;

	len = unsigned_len_base(n, lst->base);
	mlen = len;
	len--;
	while (len >= 0)
	{
		if ((n % lst->base) < 10)
			tmp[len--] = (n % lst->base) + 48;
		else
			tmp[len--] = (n % lst->base) + (lst->maj == 1 ? 55 : 87);
		n = n / lst->base;
	}
	put_buff(lst, tmp, mlen, 0);
}
