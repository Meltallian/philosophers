/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:50:51 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/11 11:51:03 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c)
{
	if ((c < 65 || c > 90) && (c < 97 || c > 122))
		return (c);
	if (c > 64 && c < 91)
		return (c + 32);
	if (c > 96 && c < 123)
		return (c);
	else
		return (0);
}
/*
int main(int ac, char **av)
{
    if(ac != 2)
        return(1);

    int src;
    src = av[1][0];

    printf("Result: %d\n", ft_tolower(src));
    printf("Result: %d\n", tolower(src));
    return(0);
} */