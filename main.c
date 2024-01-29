/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/29 15:50:19 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	is_int(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] > 57 || av[i][j] < 48)
			{
				ft_printf("wrong synthax");
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	init(t_tab *tab, int ac, char **av)
{
	if (ac == 1)
		exit (1);
	if (ac < 5 || ac > 6)
	{
		ft_printf("wrong synthax");
		exit (1);
	}
	is_int(av, ac);
	tab->fork = ft_atoi(av[1]);
	tab->t_die = ft_atoi(av[2]);
	tab->t_eat = ft_atoi(av[3]);
	tab->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		tab->min_meal = ft_atoi(av[5]);
}

int	main(int ac, char **av)
{
	t_tab	tab;

	init(&tab, ac, av);
	return (0);
}