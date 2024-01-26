/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:23 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/05 16:39:44 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static size_t	size_count(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	isneg(int n)
{
	int	neg;

	neg = 0;
	if (n >= 0)
		neg = 1;
	else if (n < 0)
		neg = -1;
	return (neg);
}

static char	*buff(char *str, long int i, int neg, int n)
{
	if (neg >= 0)
	{
		while (--i >= 0)
		{
			str[i] = (n % 10) + 48;
			n = n / 10;
		}
	}
	else if (neg < 0)
	{
		n = n * -1;
		while (--i > 0)
		{
			str[i] = (n % 10) + 48;
			n = n / 10;
		}
		str[i] = 45;
	}
	return (str);
}

char	*ft_itoa(long int n)
{
	char			*str;
	long int		i;
	int				neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = size_count(n);
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (0);
	neg = isneg(n);
	str = buff(str, i, neg, n);
	return (str);
}
/*
int	main(void)
{
	int	n;

	n = -2147647;
	printf("%s", ft_itoa(n));
	return (0);
} */
