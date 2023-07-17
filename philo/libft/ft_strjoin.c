/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 07:18:13 by tkulket           #+#    #+#             */
/*   Updated: 2022/09/20 19:36:21 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	tmp = malloc(sizeof(char) * (i + j + 1));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, s1, i);
	ft_memcpy(tmp + i, s2, j);
	tmp[i + j] = '\0';
	return (tmp);
}
