/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:07:04 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/09 15:07:57 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

const char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lit;

	i = 0;
	lit = 0;
	if (*little == '\0')
		return (big);
	while (little[lit])
		lit++;
	while (big[i] && i < len)
	{
		if (big[i] == little[0] && i + lit <= len)
		{
			j = 0;
			while (j < lit && big[i + j] == little[j])
			{
				j++;
				if (j == lit)
					return (&big[i]);
			}
		}
		i++;
	}
	return (0);
}

/* int main(int ac, char **av)
{
	if(ac != 3)
		return(1);

	const char *big;
	const char *little;
	big = av[1];
	little = av[2];

	printf("Result: %s\n", ft_strnstr(big, little, 10));
//	printf("Result: %d\n", strnstr(big, little, 10));
	return(0);
} */