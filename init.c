/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:55:27 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/13 11:04:54 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_assist_2(t_tab *tab, int ac, char **av)
{
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
		return (0);
	}
	return (1);
}

int	init_assist(t_tab *tab, int ac, char **av)
{
	int	i;

	init_assist_2(tab, ac, av);
	set_philo(tab, ac);
	name(tab);
	tab->fork = malloc (tab->n_f * sizeof(t_fork));
	if (!tab->fork)
	{
		printf("fork malloc issue\n");
		return (0);
	}
	set_fork(tab);
	i = 0;
	while (i < tab->n_f)
	{
		if (pthread_mutex_init(&(tab->fork[i].mutex), NULL) != 0)
		{
			printf("thread issue\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	init(t_tab *tab, int ac, char **av)
{
	if (!(init_assist(tab, ac, av)))
		return (0);
	tab->dead = 0;
	pthread_mutex_init(&tab->running, NULL);
	return (1);
}

int	threads(t_tab *tab)
{
	int	i;

	i = 0;
	tab->st = get_time_in_ms();
	while (i < tab->n_f)
	{
		if (pthread_create(&(tab->ph[i].p), NULL, &philo_routine, (void *)&(tab->ph[i])) != 0)
			return (0);
		i++;
	}
	if (pthread_create(&(tab->p), NULL, &monitor_routine, (void *)&(tab)) != 0)
		return (0);
	i = 0;
	while (i < tab->n_f)
	{
		if (pthread_join(tab->ph[i].p, NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_join(tab->p, NULL) != 0)
		return (0);
	return (1);
}