/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:12:59 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/11 11:20:11 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (n == 0 || dlen >= n)
		return (n + slen);
	i = 0;
	while (src[i] && (dlen + i) < n - 1)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}

/* int main()
{
	const char *src = "coucou world";
	char dest[20] = "";
	dest[0] = '\0';
	printf("Result: %lu\n", strlcat(dest, src, 20));
	printf("Result: %lu\n", ft_strlcat(dest, src, 20));

	return(0);
} */
