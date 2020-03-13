/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:10:54 by vronchin          #+#    #+#             */
/*   Updated: 2020/03/06 16:36:18 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_conversion(t_format *lst, char *str, int ret)
{
	ret = lst_putoption(lst, str, 1);
	lst_find_base(lst);
	if (lst->conv == 's')
		conv_string(lst);
	else if (lst->conv == 'd' || lst->conv == 'i' || lst->conv == 'x'
			|| lst->conv == 'X' || lst->conv == 'u' || lst->conv == 'p')
		conv_int(lst);
	else if (lst->conv != 0)
		conv_char(lst);
	return (ret);
}

int		lst_putoption(t_format *lst, char *str, int count)
{
	int		neg;

	neg = 1;
	lst_zeroing(lst);
	while (str[count] != '\0' && lst->conv == 0)
	{
		if (str[count] == '.')
			lst->point += str[count++] - 45;
		else if (str[count] == '0' && lst->point == 0)
			lst->zero += str[count++] - 47;
		else if (str[count] == '#')
			lst->hash = str[count++] - 34;
		else if (str[count] == ' ')
			lst->space = str[count++] - 31;
		else if (ft_isdigit(str[count]) == 1 || str[count] == '-'
		|| str[count] == '*')
			count = lst_put_digit(lst, str, count, &neg);
		else if (str[count] == 'd' || str[count] == 'i' || str[count] == 'u'
		|| str[count] == 'x' || str[count] == 'X' || str[count] == 's'
		|| str[count] == 'c' || str[count] == 'p' || str[count] == '%')
			lst->conv = str[count++];
		else
			count++;
	}
	return (count);
}

int		lst_put_digit(t_format *lst, char *str, int count, int *neg)
{
	int nb_tmp;

	nb_tmp = 0;
	if (str[count] == '+')
		lst->sign = str[count++];
	else if (str[count] == '-')
		(*neg) = str[count++] - 46;
	else if (ft_isdigit(str[count]) == 1 || str[count] == '*')
	{
		while (str[count] >= '0' && str[count] <= '9')
			nb_tmp = (nb_tmp * 10) + (str[count++] - '0');
		if ((str[count] == '*') && (count++))
			nb_tmp = va_arg(lst->va_copy, int);
		if (lst->point == 0)
		{
			((*neg) == -1 && nb_tmp < 0) ? (*neg) = 1 : 1;
			lst->field = (nb_tmp * (*neg));
		}
		else
		{
			(nb_tmp < 0) ? lst->point = 0 : 1;
			lst->preci = nb_tmp;
		}
	}
	return (count);
}

void	lst_find_base(t_format *lst)
{
	if (lst->conv == 'x' || lst->conv == 'X' || lst->conv == 'p')
		lst->base = 16;
	else
		lst->base = 10;
	if (!ft_islowercase(lst->conv))
		lst->maj = 1;
	lst_not_defined(lst);
}
