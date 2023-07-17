/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 07:15:56 by tkulket           #+#    #+#             */
/*   Updated: 2023/05/29 13:51:44 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tmp;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > (size_t)ft_strlen(s))
		return (ft_calloc(1, 1));
	if (ft_strlen(s) - start < len)
		len = (size_t)ft_strlen(s + start);
	tmp = malloc(sizeof(*s) * len + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
