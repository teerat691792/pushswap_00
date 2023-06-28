/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 01:56:41 by tkulket           #+#    #+#             */
/*   Updated: 2022/09/20 19:04:11 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			ft_lstclear(&tmp, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
