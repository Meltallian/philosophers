/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:00:31 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/11 09:57:36 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t		i;
	const char	*s;

	s = src;
	i = 0;
	while (i < n)
	{
		if (s[i] == (char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (0);
}

/*
int main(int ac, char **av)
{
	if(ac != 2)
		return(1);

	char *check;
	check = av[1];

	printf("Result: %d\n", ft_strlen(check));
	printf("Result: %ld\n", strlen(check));
	return(0);
} */