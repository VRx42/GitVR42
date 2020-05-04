/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:26:21 by vronchin          #+#    #+#             */
/*   Updated: 2020/04/30 17:26:23 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#	ifndef __CUB3D_H
#	define __CUB3D_H
#	include <math.h>
#	include <stdio.h>
#	include "../get_next_line/get_next_line.h"
#	include "../libft/libft.h"
#	include "../minilibx/mlx.h"

#	define INVISI_CHAR "\t\v\r\f "

typedef	enum				e_error
{
	ERROR,
	SCREEN_ERROR,
	PATH_ERROR,
	UNKNOW_ARG,
    ARGUMENT_ERROR,
	RGB_ERROR,
	MAP_ERROR,
	SUCCESS
}							t_error;

typedef struct				s_arg
{
	int						screen_w;
	int						screen_h;
	char					*no;
	char					*so;
	char					*we;
	char					*ea;
	char					*sprite;
}                           t_arg;

typedef struct				s_rgb
{
	int						r;
	int						g;
	int						b;
}							t_rgb;

typedef struct				s_map
{
	char					*line;
	struct s_map			*next;
}							t_map;

/*
**	main.c
*/


/*
**	parser.c
*/
int			check_floor_ceil_b(t_arg *arg, char *buff, int i);
int			check_floor_ceil(t_arg *arg, char *buff);

/*
**	parser_tex.c
*/
int			check_path(t_arg *arg, char *buff);
int			check_path1(char *orientation, char *buff, int i, t_arg *arg);
int			check_screen(t_arg *arg, char *buff, int i);
int			fetch_arguments(t_arg *arg, char *buff);

#	endif