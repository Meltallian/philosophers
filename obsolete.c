/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obsolete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:23:57 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/07 13:15:25 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/*
void	to_eat(t_tab *tab, int i)
{
	if (tab->ph[i].state == 'e')
	{
		printf("%s is eating\n", tab->ph[i].name);
		tab->ph[i].state = 's';
		tab->fork[i].state = 'f';
		if (tab->ph[i].id == tab->n_f - 1)
			tab->fork[0].state = 'f';
		if (tab->ph[i].id != tab->n_f - 1)
			tab->fork[i + 1].state = 'f';
	}
}
void	to_sleep_and_think(t_tab *tab, int i)
{
	if (tab->ph[i].state == 's')
	{
		printf("%s is sleeping\n", tab->ph[i].name);
		tab->ph[i].state = 't';
	}
	if (tab->ph[i].state == 't')
	{
		printf("%s is thinking\n", tab->ph[i].name);
		tab->ph[i].state = 'f';
	}
}

void	action(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->min_meal)
	{
		pthread_mutex_lock(&(tab->fork[i].mutex));
		if ((tab->ph[i].state == 'f' || tab->ph[i].state == 'r') &&
			(tab->fork[i].id == tab->ph[i].id || tab->fork[i].id == tab->ph[i].id + 1) &&
			tab->fork[i].state == 'f' && tab->fork[i + 1].state == 'f')
		{
			printf("%s has taken the fork %d\n", tab->ph[i].name, tab->fork[i].id);
			if (tab->ph[i].state == 'r')
				tab->ph[i].state = 'e';
			if (tab->ph[i].state == 'f')
				tab->ph[i].state = 'r';
			tab->fork[i].state = 't';
		}

		if ((tab->ph[tab->n_f - 1].state == 'f' || tab->ph[tab->n_f - 1].state == 'r') &&
			(tab->fork[i].id == tab->ph[tab->n_f - 1].id || tab->fork[0].id == tab->ph[tab->n_f - 1].id) &&
			tab->fork[i].state == 'f')
		{
			printf("%s has taken the fork %d\n", tab->ph[i].name, tab->fork[i].id);
			if (tab->ph[i].state == 'r')
				tab->ph[i].state = 'e';
			if (tab->ph[i].state == 'f')
				tab->ph[i].state = 'r';
		}
		pthread_mutex_unlock(&(tab->fork[i].mutex));
		i++;
	}
}

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
	tab->n_f = atoi(av[1]);
	tab->t_die = atoi(av[2]);
	tab->t_eat = atoi(av[3]);
	tab->t_sleep = atoi(av[4]);
	if (ac == 6)
		tab->min_meal = atoi(av[5]);
	tab->ph = malloc (tab->n_f * sizeof(t_philo));
	tab->fork = malloc (tab->n_f * sizeof(t_fork));
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
	if (pthread_create(&p1, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_create(&p2, NULL, &routine, NULL) != 0)
		return 2;
	if (pthread_create(&p3, NULL, &routine, NULL) != 0)
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
 */