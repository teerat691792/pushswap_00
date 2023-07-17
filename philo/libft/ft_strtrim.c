/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 08:10:08 by tkulket           #+#    #+#             */
/*   Updated: 2022/09/20 21:40:13 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_checkset(char c, char const *set)
{
	if (ft_strchr(set, c))
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	bkwd;
	size_t	frwd;
	size_t	len;
	char	*tmp;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	bkwd = len - 1;
	frwd = 0;
	while (ft_checkset(s1[frwd], set) && frwd < len)
		frwd++;
	if (frwd == len || !len)
		return (ft_calloc (1, 1));
	while (ft_checkset(s1[bkwd], set) && bkwd > frwd)
		bkwd--;
	len = bkwd - frwd + 1;
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, (s1 + frwd), len);
	tmp[len] = '\0';
	return (tmp);
}
