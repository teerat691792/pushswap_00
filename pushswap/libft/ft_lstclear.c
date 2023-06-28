/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 01:51:07 by tkulket           #+#    #+#             */
/*   Updated: 2022/09/20 19:45:48 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{	
	t_list	*tmp;

	if (!(*lst))
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = tmp;
	}
	*lst = NULL;
}
