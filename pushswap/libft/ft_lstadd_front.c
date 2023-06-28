/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 01:30:44 by tkulket           #+#    #+#             */
/*   Updated: 2022/09/19 23:39:41 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst)
		*lst = new;
	else
	{
		tmp = *lst;
		*lst = new;
		new->next = tmp;
	}
}
