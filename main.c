/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/02 09:09:35 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init(t_tab *tab, int ac, char **av)
{
	if (ac == 1)
		exit (1);
	if (ac < 5 || ac > 6)
	{
		printf("wrong syntax");
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

	int	mails = 0;

void	*routine(void *arg)
{
	pthread_mutex_t	*mutex = (pthread_mutex_t *)arg;
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(mutex);
		mails++;
		pthread_mutex_unlock(mutex);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_tab			tab;
	pthread_t	p1, p2, p3;
	pthread_mutex_t	mutex;

	init(&tab, ac, av);
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&p1, NULL, routine, &mutex) != 0)
		return 1;
	if (pthread_create(&p2, NULL, routine, &mutex) != 0)
		return 2;
	if (pthread_create(&p3, NULL, routine, &mutex) != 0)
		return 5;
	if (pthread_join(p1, NULL) != 0)
		return 3;
	if (pthread_join(p2, NULL) != 0)
		return 4;
	if (pthread_join(p3, NULL) != 0)
		return 6;
	pthread_mutex_destroy(&mutex);
	printf("Number of mails : %d\n", mails);
	free(tab.ph);
	return (0);
}
