/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:50:01 by tkulket           #+#    #+#             */
/*   Updated: 2023/05/29 16:01:13 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim_remain(char *collector, int nl)
{
	char	*result;
	size_t	len;

	if (!collector)
		return (NULL);
	len = ft_strnlen(collector) - nl;
	if (len == 0)
	{
		free(collector);
		return (NULL);
	}
	result = ft_strndup(collector + nl, len);
	free(collector);
	return (result);
}

char	*ft_line_return(char *collector, int nl)
{
	char	*result;

	if (!collector)
		return (NULL);
	result = ft_strndup(collector, nl);
	if (!result)
		return (NULL);
	return (result);
}

static char	*ft_read_buffer(int fd, char *buffer, char *collector)
{
	int		byte;

	byte = 1;
	while (byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte] = '\0';
		if (!collector)
			collector = ft_strndup(buffer, byte);
		else
			collector = ft_strnjoin(collector, buffer);
		if (ft_find_newline(buffer) > 0)
			break ;
	}
	free(buffer);
	return (collector);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*collector[FOPEN_MAX];
	int			nl;
	char		*buffer;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	nl = ft_find_newline(collector[fd]);
	if (nl > 0)
	{
		result = ft_line_return(collector[fd], nl);
		collector[fd] = ft_trim_remain(collector[fd], nl);
		return (result);
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	collector[fd] = ft_read_buffer(fd, buffer, collector[fd]);
	nl = ft_find_newline(collector[fd]);
	if (nl == -1)
		nl = ft_strnlen(collector[fd]);
	result = ft_line_return(collector[fd], nl);
	collector[fd] = ft_trim_remain(collector[fd], nl);
	return (result);
}
