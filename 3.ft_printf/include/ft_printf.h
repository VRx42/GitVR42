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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define ERROR	ftprintf_error
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFF_PRINTF 70

typedef struct	s_format
{
	va_list			va_lst;
	va_list			va_copy;
	char			sign;
	char			hash;
	int				minus;
	char			zero;
	char			point;
	int				preci;
	int				field;
	char			conv;
	unsigned char	*str;
	int				count;
	int				buff_count;
	char			space;
	char			*presign;
	unsigned int	base;
	char			maj;
	unsigned long	ul_nb;
	unsigned char	buff[BUFF_PRINTF];
}				t_format;

/*
** master.c
*/
int				ft_printf(const char *format, ...);
void			ft_read_format(char *str, t_format *lst, size_t i, size_t j);
void			ft_write(t_format *lst);
/*
**	lst_initialization.c
*/
t_format		*initialize_list(void);
void			lst_zeroing(t_format *lst);
/*
** format_analysis.c
*/
int				find_conversion(t_format *lst, char *str, int ret);
int				lst_putoption(t_format *lst, char *str, int count);
int				lst_put_digit(t_format *lst, char *str, int count, int *neg);
void			lst_find_base(t_format *lst);
/*
** put_convert_buffer.c
*/
void			put_buff(t_format *lst, void *tmp, size_t len, size_t index);
void			put_prefix_buff(t_format *lst, int len, int nb, int point);
void			convert_buff(t_format *lst, void *tmp, size_t len);
void			ft_space_count(t_format *lst, int len);
void			put_itoa(t_format *lst, unsigned long n);
/*
**	utils.c
*/
size_t			len_wuchart(unsigned char *str);
size_t			len_pstrn(unsigned char *str, size_t len, size_t index);
void			lst_not_defined(t_format *lst);
void			ftprintf_error(t_format *lst, char *str);
int				ft_max(int a, int b);
int				ft_abs(int a);
/*
**	conv_char.c
*/
void			pf_putchar(t_format *lst, unsigned char c, unsigned char *wc,
				int index);
void			conv_char(t_format *lst);
/*
**	conv_int.c
*/
void			conv_int(t_format *lst);
void			lst_putint(t_format *lst);
void			lst_putnb_signed_nb(t_format *lst);
void			lst_putnb_unsigned_nb(t_format *lst);
int				unsigned_len_base(unsigned long nb, size_t base);
/*
** conv_string.c
*/
void			conv_string(t_format *lst);
void			pf_string(t_format *lst, unsigned char *str, int index);
unsigned char	*ft_ustrdup(unsigned char *s1);
unsigned char	*ft_strudup(char *s1);

/*
** fonctions_nulles.c
*/
int				ft_abs(int a);
int				ft_max(int a, int b);
#endif
