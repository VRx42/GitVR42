/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:54:20 by vronchin          #+#    #+#             */
/*   Updated: 2019/11/20 17:36:43 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr->next)
	{
		del(ptr->content);
		ptr = ptr->next;
		free(*lst);
		*lst = (*lst)->next;
	}
	del(ptr->content);
	free(*lst);
	*lst = NULL;
}
