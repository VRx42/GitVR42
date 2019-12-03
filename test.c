/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:44:51 by vronchin          #+#    #+#             */
/*   Updated: 2019/11/27 16:52:20 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd;

	fd = 0;
	//fd = open("~/Documents/2.Cursus_C_42/get_next_line/toto.txt", O_RDONLY);
	printf("fd = %u", fd);
	//close(fd);
	//printf("fd = %u", fd);
	return (0);
}

