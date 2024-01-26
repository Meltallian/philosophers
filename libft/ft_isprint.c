/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:00:57 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/10 16:06:10 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int arg)
{
	if (arg >= 32 && arg <= 126)
		return (1);
	else
		return (0);
}

/* int	main(int ac, char **av)
{
	int	check;
	check = av[1][0];

	if(ac != 2)
		return(1);
	else
		printf("Result: %d\n", ft_isprint(check));
		printf("Result: %d\n", isprint(check));
	return(0);
} */