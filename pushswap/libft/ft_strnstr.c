/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:31:28 by tkulket           #+#    #+#             */
/*   Updated: 2022/09/20 19:15:00 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (*needle == 0)
		return ((char *)haystack);
	if (*haystack == 0)
		return (0);
	i = 0;
	j = 0;
	tmp = (char *)haystack;
	while (tmp[i] != '\0' && i < len)
	{
		while (tmp[i + j] == needle[j] && needle[j] && i + j < len)
		{
			j++;
		}
		if (needle[j] == '\0')
			return (tmp + i);
		else
			j = 0;
		i++;
	}
	return (0);
}
