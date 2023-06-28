/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 01:37:17 by tkulket           #+#    #+#             */
/*   Updated: 2022/09/20 21:34:40 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	char	a;
	int		i;

	a = (char)c;
	tmp = (char *)s;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == a)
			return ((char *)tmp + i);
		i++;
	}
	if (!a && tmp[i] == '\0')
	{
		return ((char *)tmp + i);
	}
	return (0);
}
