/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:45 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/09 17:03:37 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
	{
		return (1);
	}
	else
		return (0);
}

/* int main(int ac, char **av)
{
	int check;
	check = av[1][0];

	if(ac != 2)
		return(1);
	else
		printf("Result: %d\n", ft_isalpha(check));
	return(0);
} */
