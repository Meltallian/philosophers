/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:01:40 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/09 17:01:48 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_isdigit(int arg)
{
	if (arg > 47 && arg < 58)
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
		printf("Result: %d\n", ft_isdigit(check));
		printf("Result: %d\n", isdigit(check));
	return(0);
} */