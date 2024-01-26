/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:09:53 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/09 18:44:33 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

/* int main(int ac, char **av)
{
	if(ac != 2)
		return(1);

	char *check;
	check = av[1];

	printf("Result: %d\n", ft_strlen(check));
	printf("Result: %ld\n", strlen(check));
	return(0);
} */