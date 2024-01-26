/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:14:27 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/12 10:20:19 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc((ft_strlen(src)+1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/* int main(int ac, char **av)
{
	if(ac != 3)
		return(1);

	size_t nmemb;
	size_t size;
	nmemb = av[1];
	size = av[2];

	printf("Result: %d\n", ft_calloc(nmemb, size));
	return(0);
} */