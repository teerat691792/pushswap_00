/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 01:43:16 by tkulket           #+#    #+#             */
/*   Updated: 2022/09/20 21:32:59 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = ft_strlen(dst);
	i = ft_strlen(src);
	if (!dst)
		return (0);
	if (n <= j)
		return (n + i);
	k = 0;
	while (src[k] && k + j < n - 1)
	{
		dst[k + j] = src[k];
		k++;
	}
	dst[k + j] = '\0';
	return (i + j);
}
