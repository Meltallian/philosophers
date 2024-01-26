/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:20:41 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/26 13:42:25 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_count(unsigned int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*buff(char *str, int i, unsigned int n)
{
	while (--i >= 0)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}

char	*ft_unsitoa(unsigned int n)
{
	char	*str;
	int		i;

	i = size_count(n);
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (0);
	str = buff(str, i, n);
	return (str);
}
