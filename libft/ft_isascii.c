/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:01:55 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/10 15:50:38 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int arg)
{
	if (arg >= 0 && arg <= 127)
		return (1);
	else
		return (0);
}

/*  int main(int ac, char **av)
{
	int check;

	if(ac != 2)
		return(1);

	check = av[1][0];
	printf("Result: %d\n", ft_isascii(check));
	printf("Result: %d\n", isascii(check));
	return(0);
} */