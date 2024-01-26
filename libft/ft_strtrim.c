/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:23 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/12 14:41:13 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trim = ft_calloc((end - start + 1), sizeof(char));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, s1 + start, end - start + 1);
	return (trim);
}
/*
int main()
{
	char *str = "";
	char *set = "";
	printf("%s\n", ft_strtrim(str, set));
	return(0);
} */