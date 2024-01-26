/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:16:12 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/10 16:11:38 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&src[i]);
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