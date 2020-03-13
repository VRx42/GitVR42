/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:10:54 by vronchin          #+#    #+#             */
/*   Updated: 2020/02/14 14:10:55 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		lst_zeroing(t_format *lst)
{
	lst->minus = 0;
	lst->zero = 0;
	lst->space = 0;
	lst->preci = 0;
	lst->conv = 0;
	lst->point = 0;
	lst->field = 0;
	lst->maj = 0;
	lst->base = 0;
	lst->ul_nb = 0;
	lst->presign = "";
	lst->hash = 0;
}

t_format	*initialize_list(void)
{
	t_format *lst;

	if (!(lst = (t_format*)malloc(sizeof(t_format))))
		ERROR(lst, "MALLOC:initialize_list");
	lst->count = 0;
	lst->buff_count = 0;
	lst->str = NULL;
	return (lst);
}
