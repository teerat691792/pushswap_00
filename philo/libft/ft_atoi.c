/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:46:43 by tkulket           #+#    #+#             */
/*   Updated: 2022/09/05 17:32:11 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	x;
	int	minus;
	int	n;

	n = 0;
	minus = 1;
	while ((str[n] >= 9 && str[n] <= 13) || str[n] == ' ')
	{
		n++;
	}
	if (str[n] == '-' || str[n] == '+')
	{	
		if (str[n] == '-')
			minus = -1;
		n++;
	}
	if (str[n] == '-' || str[n] == '+')
		return (0);
	x = 0;
	while (str[n] >= '0' && str[n] <= '9')
	{
		x = (x * 10) + (str[n] - '0');
		n++;
	}
	return (minus * x);
}
