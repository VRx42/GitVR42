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

int		ft_printf(const char *format, ...)
{
	t_format	*lst;

	lst = initialize_list();
	va_start(lst->va_lst, format);
	ft_read_format((char*)format, lst, 0, 0);
	ft_write(lst);
	free(lst);
	return (lst->count + lst->buff_count);
}

void	ft_read_format(char *str, t_format *lst, size_t i, size_t j)
{
	va_copy(lst->va_copy, lst->va_lst);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] != '%')
			j++;
		put_buff(lst, &str[i], j, 0);
		if (str[i + j] == '%')
			i += find_conversion(lst, (str + i + j), 0);
		i += j;
	}
	va_end(lst->va_lst);
	va_end(lst->va_copy);
}

void	ft_write(t_format *lst)
{
	if (lst->count != 0)
		write(1, lst->str, lst->count);
	if (lst->buff_count != 0)
		write(1, lst->buff, lst->buff_count);
	if (lst->str != NULL)
		free(lst->str);
}
