/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helloworld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:24:31 by vronchin          #+#    #+#             */
/*   Updated: 2020/04/30 12:24:34 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cube3d.h"

typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
}                 data_t;

int main(void)
{
    data_t        data;
    void          *img1_ptr;

    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
        return (EXIT_FAILURE);
    img1_ptr = mlx_new_image(data.mlx_ptr, 640, 480);
    
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}