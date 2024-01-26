/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:23 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/13 15:09:41 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static size_t	word_count(const char *s, const char c)
{
	size_t	i;
	size_t	j;
	size_t	index;

	i = 0;
	j = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c && index == 0)
		{
			index = 1;
			j++;
		}
		else if (s[i] == c)
			index = 0;
		i++;
	}
	return (j);
}

static char	*ft_buff(const char *str, size_t start, size_t end)
{
	char	*buff;
	int		i;

	i = 0;
	buff = (char *)malloc((end - start + 1) * sizeof(char));
	if (!buff)
		return (0);
	while (start < end)
		buff[i++] = str[start++];
	buff[i] = '\0';
	return (buff);
}

char	**ft_split(const char *s, const char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	i = 0;
	j = 0;
	index = -1;
	if (!s)
		return (0);
	split = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!split)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_buff(s, index, i);
			index = -1;
		}
		i++;
	}
	return (split);
}
/*
int main()
{
	char *str = "    tripouille 42  ";
	char c = ' ';
	size_t i = 0;
	while (str[i])
	{
		printf("%s\n", ft_split(str, c)[i]);
		i++;
	}
	return(0);
} */