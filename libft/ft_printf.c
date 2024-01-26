/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:51:35 by jbidaux           #+#    #+#             */
/*   Updated: 2023/11/14 14:58:58 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_usitoa(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	tmp;

	len = 1;
	tmp = n;
	while (tmp > 9)
	{
		tmp = tmp / 10;
		len++;
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	while (len > 0)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

t_ull	ft_conv_u(unsigned int num)
{
	char			*str;
	unsigned int	j;

	j = 0;
	str = ft_usitoa(num);
	if (!str)
		return (0);
	while (str[j])
	{
		ft_putchar(str[j]);
		j++;
	}
	free(str);
	return (j);
}

t_ull	ft_format(va_list va, char *format, t_ull	*i)
{
	t_ull	j;

	j = 0;
	if (*format == 'd')
		j += ft_conv_d(va_arg(va, int));
	else if (*format == 'i')
		j += ft_conv_d(va_arg(va, int));
	else if (*format == 'c')
		j += ft_conv_c(va_arg(va, int));
	else if (*format == 's')
		j += ft_conv_s(va_arg(va, char *));
	else if (*format == 'p')
		j += ft_conv_p(va_arg(va, t_ull));
	else if (*format == 'u')
		j += ft_conv_u(va_arg(va, unsigned int));
	else if (*format == 'x')
		j += ft_conv_x(va_arg(va, unsigned int));
	else if (*format == 'X')
		j += ft_conv_capx(va_arg(va, unsigned int));
	else if (*format == '%')
		j += ft_putchar('%');
	(*i)++;
	return (j);
}

int	ft_printf(const char *str, ...)
{
	t_ull	i;
	t_ull	counter;
	va_list	va;

	i = 0;
	counter = 0;
	va_start(va, str);
	while (str[i])
	{
		if (str[i] == '%')
			counter += ft_format(va, (char *)&str[i + 1], &i);
		else
			counter += ft_putchar(str[i]);
		i++;
	}
	va_end(va);
	return (counter);
}
