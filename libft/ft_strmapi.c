/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:13:36 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/16 11:55:59 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*substr;

	if (!s || !f)
		return (0);
	substr = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (s[i])
	{
		substr[i] = f(i, s[i]);
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
static char	f(unsigned int index, char str)
{
	if (index % 2 == 0)
		return ft_toupper(str);
	else
		return (str);
}

int main()
{
	char *s = "helloworld";
	printf("%s", ft_strmapi(s, f));
	return (0);
} */