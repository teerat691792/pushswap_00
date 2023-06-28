/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:29:57 by tkulket           #+#    #+#             */
/*   Updated: 2022/09/13 23:59:48 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*s;
	size_t			i;

	tmp = dst;
	s = (unsigned char *)src;
	if (n == 0 || dst == src)
		return (dst);
	if (!dst && !src)
		return (0);
	if ((size_t)dst < (size_t)src)
		ft_memcpy(tmp, s, n);
	else
	{
		i = n;
		while (i--)
			tmp[i] = ((unsigned char *)s)[i];
	}
	return (dst);
}						
