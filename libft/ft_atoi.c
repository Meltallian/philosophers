/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:23 by jbidaux           #+#    #+#             */
/*   Updated: 2023/12/05 15:35:56 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *str)
{
	long int	n;
	int			i;
	int			neg;

	neg = 1;
	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			neg = -1;
		i++;
	}
	if (str[i] == 43 || str[i] == 45)
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = (n + (str[i] - 48)) * 10;
		i++;
	}
	return (neg * (n / 10));
}

/* int main(int ac, char **av)
{
	if(ac != 2)
		return(1);

	char *str;
	str = av[1];

	printf("Result: %d\n", ft_atoi(str));
	return(0);
} */