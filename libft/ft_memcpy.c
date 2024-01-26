/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:44:13 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/18 12:08:23 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src2;
	char		*dest2;
	size_t		i;

	dest2 = dest;
	i = 0;
	src2 = src;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
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