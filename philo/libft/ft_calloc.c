/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:06:04 by tkulket           #+#    #+#             */
/*   Updated: 2022/09/20 20:43:14 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (0);
	tmp = malloc(size * count);
	if (!tmp)
		return (0);
	ft_bzero(tmp, count * size);
	return (tmp);
}
