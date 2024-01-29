/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/29 16:17:51 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init(t_tab *tab, int ac, char **av)
{
	if (ac == 1)
		exit (1);
	if (ac < 5 || ac > 6)
	{
		printf("wrong synthax");
		exit (1);
	}
	is_int(av, ac);
	tab->fork = atoi(av[1]);
	tab->t_die = atoi(av[2]);
	tab->t_eat = atoi(av[3]);
	tab->t_sleep = atoi(av[4]);
	if (ac == 6)
		tab->min_meal = atoi(av[5]);
	tab->ph = malloc (tab->fork * sizeof(t_philo));
}

int	main(int ac, char **av)
{
	t_tab	tab;

	init(&tab, ac, av);
	free(tab.ph);
	return (0);
}
