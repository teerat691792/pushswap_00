/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:37:06 by tkulket           #+#    #+#             */
/*   Updated: 2022/09/20 20:46:21 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

/*
int	main(void)
{
	t_list *w, *x, *y, *z, *i;
//	t_list *tmp;
//	int e;
	int	a = 1;
	int	b = 2;
	int	c = 3;
	int	d = 4;
	int	e = 5;

	w = ft_lstnew(&a);
	x = ft_lstnew(&b);
	y = ft_lstnew(&c);
	z = ft_lstnew(&d);
	ft_lstadd_front(&w,x);
	ft_lstadd_front(&x,y);
	ft_lstadd_front(&y,z);	
//		printf("content	=%d\n",(*(int*)z->content));
//		printf("next	=%d\n",(*(int*)z->next));
//		printf("content	=%d\n",(*(int*)y->content));
//		printf("next	=%d\n",(*(int*)y->next));
//		printf("content	=%d\n",(*(int*)x->content));
//		printf("next	=%d\n",(*(int*)x->next));
//		printf("content	=%d\n",(*(int*)w->content));
//		printf("next	=%d\n",(*(int*)w->next));

	while (z)
	{
		printf("while address	=%d\n",(*(int*)z));
		printf("while content	=%d\n",(*(int*)z->content));
		if (z->next != NULL)
		printf("while next	=%d\n",(*(int*)z->next));
		else
			printf("END");
		z = z->next;
	}

	printf("init z content	=%d\n",(*(int*)z->content));
//	printf("\n+++ size +++++\n");
//	e = ft_lstsize(z);
//	printf("e	=%d\n",e);
//	printf("final z content	=%d\n",(*(int*)z->content));
	
//	printf("\n\n++ last ++++++\n");
//	tmp = ft_lstlast(x);
	printf("\n\n+++ back +++++\n");
	
	i = ft_lstnew(&e);
	ft_lstadd_back(&z,i);
	while (z)
	{
		printf("while address	=%d\n",(*(int*)z));
		printf("while content	=%d\n",(*(int*)z->content));
		if (z->next != NULL)
		printf("while next	=%d\n",(*(int*)z->next));
		else
			printf("END");
		z = z->next;
	}

	return (0);
}
*/
