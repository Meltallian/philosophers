/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:48 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/09 17:05:24 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalnum(int arg)
{
	if ((arg > 64 && arg < 91) || (arg > 96 && arg < 123)
		|| (arg > 47 && arg < 58))
		return (1);
	else
		return (0);
}

/* int main(int ac, char **av)
{
	int check;
	check = av[1][0];

	if(ac != 2)
		return(1);
	else
		printf("Result: %d\n", ft_isalnum(check));
		printf("Result: %d\n", isalnum(check));
	return(0);
} */