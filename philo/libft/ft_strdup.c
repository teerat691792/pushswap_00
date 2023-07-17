/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:22:20 by tkulket           #+#    #+#             */
/*   Updated: 2022/09/20 20:44:40 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;
	int		j;

	i = 0;
	while (s1[i])
		i++;
	dest = (char *)malloc(sizeof(*s1) *(i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (s1[j])
	{
		dest[j] = s1[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
