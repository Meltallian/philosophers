/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:23 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/10 12:12:57 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	res = (char *)malloc((ft_strlen(s) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

/* int main()
{
//	if(ac != 4)
//		return(1);
	const char *s = "I am";
	const char *s2 = " pepegapog";
	char *res = ft_strjoin(s, s2);
	size_t i = 0;
	printf("Result: %s\n", res);
	while(res[i])
	{
		printf("%c", res[i]);
		i++;
	}
	return(0);
} */