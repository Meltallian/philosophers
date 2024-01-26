/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:51:18 by jbidaux           #+#    #+#             */
/*   Updated: 2023/11/14 14:51:59 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ull	ft_conv_x(unsigned int n)
{
	char	hexa[16];
	char	result[16];
	int		index;
	int		j;

	index = 0;
	ft_memcpy(hexa, (char [16]){'0', '1', '2', '3', '4', '5', '6',
		'7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'}, 16);
	if (!n)
	{
		ft_putchar(hexa[0]);
		return (1);
	}
	while (n >= 16)
	{
		result[index++] = hexa[n % 16];
		n /= 16;
	}
	result[index++] = hexa[n % 16];
	j = index - 1;
	while (j >= 0)
		ft_putchar(result[j--]);
	return (index);
}

t_ull	ft_conv_capx(unsigned int n)
{
	char	hexa[16];
	char	result[16];
	int		index;
	int		j;

	index = 0;
	ft_memcpy(hexa, (char [16]){'0', '1', '2', '3', '4', '5', '6',
		'7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}, 16);
	if (!n)
	{
		ft_putchar(hexa[0]);
		return (1);
	}
	while (n >= 16)
	{
		result[index++] = hexa[n % 16];
		n /= 16;
	}
	result[index++] = hexa[n % 16];
	j = index - 1;
	while (j >= 0)
		ft_putchar(result[j--]);
	return (index);
}

t_ull	p_helper(t_ull n)
{
	char	hexa[16];
	char	result[16];
	int		index;
	int		j;

	index = 0;
	ft_memcpy(hexa, (char [16]){'0', '1', '2', '3', '4', '5', '6',
		'7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'}, 16);
	write (1, "0x", 2);
	if (!n)
	{
		ft_putchar(hexa[0]);
		return (1);
	}
	while (n >= 16)
	{
		result[index++] = hexa[n % 16];
		n /= 16;
	}
	result[index++] = hexa[n % 16];
	j = index - 1;
	while (j >= 0)
		ft_putchar(result[j--]);
	return (index);
}

t_ull	ft_conv_p(t_ull num)
{
	t_ull	i;

	i = 0;
	i = p_helper(num);
	return (i + 2);
}

t_ull	ft_conv_percent(int c)
{
	ft_putchar(c);
	return (1);
}

/*
void	str_print(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		putchar(&str[i]);
		i++;
	}
}

char	*reverse(char *str)
{
	size_t	i;
	char	*reverse;
	size_t	size;

	size = ft_strlen(str);
	reverse = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!reverse)
		return (0);
	i = 0;
	while (size > 0)
		reverse[i++] = str[--size];
	reverse[i] = '\0';
	return (reverse);
}
 */
/* int	hexacount(unsigned int n)
{
	char	*num;
	size_t	count;

	num = ft_usitoa(n);
	count = ft_strlen(num);

} */