/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:10:30 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/13 11:11:17 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i + 1 < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (n > 0)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
/*
int main()
{
    char src[] = "";
    char dest[] = "";
//    memset(dest, 'A', 10);
    printf("%ld\n", ft_strlcpy(dest, src, 5));
    printf("%lu\n", strlcpy(dest, src, 5));
    printf("%s\n", src);
    printf("%s\n", dest);
    return 0;
} */