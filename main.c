/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/15 13:46:56 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->satiated = get_time_in_ms();
	while (1)
	{
		if (philo->tab->dead == 1)
			break ;
		if (philo->state == 'o')
			break ;
		action(philo);
	}
	return (NULL);
}

int	monitor(t_tab *tab)
{
	int		i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&tab->running);
		if (get_time_in_ms() - tab->ph[i].satiated > tab->t_die)
		{
			printf("%ld %s died\n", get_time_in_ms()
				- tab->st, tab->ph[i].name);
			tab->dead = 1;
			pthread_mutex_unlock(&tab->running);
			break ;
		}
		if (tab->full == tab->n_f)
		{
			pthread_mutex_unlock(&tab->running);
			break ;
		}
		pthread_mutex_unlock(&tab->running);
		i = (i + 1) % tab->n_f;
		usleep(100);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_tab	*tab;

	tab = (t_tab *)arg;
	while (1)
	{
		monitor(tab);
		if (tab->dead == 1 || tab->full == tab->n_f)
			break ;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_tab	tab;

	if (ac == 1)
		return (1);
	if (ac < 5 || ac > 6)
	{
		printf("wrong syntax");
		return (1);
	}
	if (!(init(&tab, ac, av)))
	{
		clean(&tab);
		return (1);
	}
	threads(&tab);
	clean(&tab);
	return (0);
}
