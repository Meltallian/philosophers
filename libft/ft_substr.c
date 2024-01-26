/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:23 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/25 17:08:27 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(1 * sizeof(char));
		if (sub)
			*sub = '\0';
		return (sub);
	}
	sub = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!sub)
		return (0);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

//The idea behind first malloc is to give a 1 byte
// space to return a 1 byte sring
//in which we store a null terminator
// if start is higher (hence after) the end of src.
/*
int main()
{
	char *str = "";
	printf("%s\n", ft_substr(str, 1, 1));
	return(0);
} */