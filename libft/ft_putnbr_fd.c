/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:02:55 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/17 09:52:56 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = n * (-1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	n = (n % 10) + '0';
	write (fd, &n, 1);
}
/*
int	main()
{
	int	i = -2147483648;
	int	fd = 1;

	ft_putnbr_fd(i, fd);
	return (0);
} */
