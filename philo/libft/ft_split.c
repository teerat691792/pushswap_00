/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 07:21:17 by tkulket           #+#    #+#             */
/*   Updated: 2023/05/29 13:51:17 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_splitsubstr(char const *s, unsigned int start, size_t len)
{
	char			*tmp;
	unsigned int	i;

	if (start > (size_t)ft_len(s))
		return (ft_calloc(1, 1));
	if (ft_len(s) - start < len)
		len = (size_t)ft_len(s + start);
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

size_t	ft_countsplit(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (!s)
		return (count);
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			count++;
		else if (s[i + 1] == '\0' && count == 0 && s[i] == c)
			return (0);
		else if (s[i + 1] == '\0' && count == 0)
			count++;
		else if (s[i + 1] == '\0' && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	size_t	count;
	size_t	b;
	size_t	i;

	if (!s)
		return (NULL);
	count = ft_countsplit(s, c);
	tmp = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (s[0] == c)
			s = ft_strchr(s, c) + 1;
		b = ft_len(s) - ft_len(ft_strchr(s, c));
		tmp[i] = ft_splitsubstr(s, 0, b);
		s = ft_strchr(s, c) + 1;
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
