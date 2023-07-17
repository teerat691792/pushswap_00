/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:50:19 by tkulket           #+#    #+#             */
/*   Updated: 2023/05/29 16:00:32 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_find_newline(char *str)
{
	int	len;
	int	i;

	if (!str)
		return (0);
	len = ft_strnlen(str);
	i = 0;
	while (i < len)
	{
		if (str[i] == '\n' )
			return (i + 1);
		if (!str)
			return (0);
		i++;
	}
	return (-1);
}

void	*ft_strncpy(char *dst, char *src, int len)
{
	int	i;

	if (!src || len == 0)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strndup(char *str, int len)
{
	char	*tmp;

	if (!str || len == 0)
		return (NULL);
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	ft_strncpy(tmp, str, len);
	return (tmp);
}

char	*ft_strnjoin(char *dst, char *src)
{
	char	*tmp;
	int		lendst;
	int		lensrc;

	lensrc = ft_strnlen(src);
	if (lensrc == 0)
		return (dst);
	lendst = ft_strnlen(dst);
	tmp = malloc(sizeof(char) * (lensrc + lendst + 1));
	if (!tmp)
		return (NULL);
	ft_strncpy(tmp, dst, lendst);
	ft_strncpy(tmp + lendst, src, lensrc);
	free (dst);
	return (tmp);
}
