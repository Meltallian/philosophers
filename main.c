/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/02 15:45:18 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_assist(t_tab *tab, int ac, char **av)
{
	if (ac == 1)
		exit (1);
	if (ac < 5 || ac > 6)
	{
		printf("wrong syntax");
		exit (1);
	}
	is_int(av, ac);
	tab->n_f = atoi(av[1]);
	tab->t_die = atoi(av[2]);
	tab->t_eat = atoi(av[3]);
	tab->t_sleep = atoi(av[4]);
	tab->min_meal = 0;
	if (ac == 6)
		tab->min_meal = atoi(av[5]);
	tab->ph = malloc (tab->n_f * sizeof(t_philo));
	if (!tab->ph)
	{
		printf("philosophers malloc issue\n");
		exit (1);
	}
	set_philo(tab, ac);
}

void	init(t_tab *tab, int ac, char **av)
{
	int	i;

	init_assist(tab, ac, av);
	tab->fork = malloc (tab->n_f * sizeof(t_fork));
	if (!tab->fork)
	{
		printf("fork malloc issue\n");
		free(tab->fork);
		exit (1);
	}
	set_fork(tab);
	i = 0;
	while (i < tab->n_f)
	{
		if(pthread_mutex_init(&(tab->fork[i].mutex), NULL) != 0)
		{
			printf("thread issue\n");
			free(tab->ph);
			free(tab->fork);
			exit (1);
		}
		i++;
	}
}



int	main(int ac, char **av)
{
	t_tab	tab;

	init(&tab, ac, av);
	clean(&tab);
	return (0);
}
