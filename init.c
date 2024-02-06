/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:55:27 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/06 15:47:57 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_assist_2(t_tab *tab, int ac, char **av)
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
}

void	init_assist(t_tab *tab, int ac, char **av)
{
	int	i;

	init_assist_2(tab, ac, av);
	set_philo(tab, ac);
	name(tab);
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
		if (pthread_mutex_init(&(tab->fork[i].mutex), NULL) != 0)
		{
			printf("thread issue\n");
			free(tab->ph);
			free(tab->fork);
			exit (1);
		}
		i++;
	}
}

int	init(t_tab *tab, int ac, char **av)
{
	int	i;

	init_assist(tab, ac, av);
	i = 0;
	while (i < tab->n_f)
	{
		if (pthread_create(&(tab->ph[i].p), NULL, &routine, (void *)tab) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < tab->n_f)
	{
		if (pthread_join(tab->ph[i].p, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
