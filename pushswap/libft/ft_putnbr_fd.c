/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 07:33:11 by tkulket           #+#    #+#             */
/*   Updated: 2022/09/20 20:46:40 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		n = (n % 10) + '0';
		write (fd, &n, 1);
	}
	else
	{
		n = (n % 10) + '0';
		write (fd, &n, 1);
	}
}

/*
int	main(void)
{
	int fd = 1;
//	ft_putnbr_fd(0,fd);
//	write(1 , "\n", 1);
	ft_putnbr_fd(123,fd);
	write(1 , "\n", 1);
//	ft_putnbr_fd(-456,fd);
//	write(1 , "\n", 1);
//	ft_putnbr_fd(INT_MAX,fd);
//	write(1 , "\n", 1);
//	ft_putnbr_fd(INT_MIN,fd);
//	write(1 , "\n", 1);
	return (0);
}
*/
