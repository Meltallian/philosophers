/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:16:59 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/13 11:06:14 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *ptr, int c, size_t n)
{
	char	*str;
	size_t	i;

	str = ptr;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
/*
int main()
{
	char	c = 'A';
	char check[20] = "mdrdelolptdr";
	printf("%s\n", ft_memset(check, c, 21));
	return(0);
} */