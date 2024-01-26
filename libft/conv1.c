/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:51:29 by jbidaux           #+#    #+#             */
/*   Updated: 2023/11/14 14:50:24 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ull	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

t_ull	ft_conv_c(char c)
{
	ft_putchar(c);
	return (1);
}

t_ull	ft_conv_d(int d)
{
	char	*str;
	t_ull	i;

	i = 0;
	str = ft_itoa(d);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	free(str);
	return (i);
}

t_ull	ft_conv_s(char *str)
{
	t_ull	i;

	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
/*
t_ull	ft_conv_u(unsigned int num)
{
	char			*str;
	unsigned int	j;

	j = 0;
	str = ft_usitoa(num);
	if (!str)
		return (0);
	while (str[j])
	{
		putchar(str[j]);
		j++;
	}
	free(str);
	return (j);
} */
