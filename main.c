/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/08 11:55:05 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	to_sleep(t_philo *philo)
{
	if (philo->state == 's')
	{
		printf("%s is sleeping\n", philo->name);
		philo->state = 't';
	}
}

void	to_think(t_philo *philo)
{
	if (philo->state == 't')
	{
		printf("%s is thinking\n", philo->name);
		philo->state = 'f';
	}
}

void	to_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&(philo->fork[philo->left_f].mutex));
		if (philo->state == 'f')
		{
			printf("%s has taken the fork %d\n", philo->name, philo->left_f);
			philo->state = 'r';
		}
		pthread_mutex_lock(&(philo->fork[philo->right_f].mutex));
		if (philo->state == 'r')
		{
			printf("%s has taken the fork %d\n", philo->name, philo->right_f);
			philo->state = 'e';
		}
		if (philo->state == 'e')
		{
			printf("%s is eating\n", philo->name);
			philo->state = 's';
		}
		pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
		pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
	}
	else
	{
		pthread_mutex_lock(&(philo->fork[philo->right_f].mutex));
		if (philo->state == 'f')
		{
			printf("%s has taken the fork %d\n", philo->name, philo->right_f);
			philo->state = 'r';
		}
		pthread_mutex_lock(&(philo->fork[philo->left_f].mutex));
		if (philo->state == 'r')
		{
			printf("%s has taken the fork %d\n", philo->name, philo->left_f);
			philo->state = 'e';
		}
		if (philo->state == 'e')
		{
			printf("%s is eating\n", philo->name);
			philo->state = 's';
		}
		pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
		pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
	}
}

void	action(t_philo *philo)
{
	to_eat(philo);
	to_sleep(philo);
	to_think(philo);
}

void	*routine(void *arg)
{
	int	i = 0;
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (i < 5)
	{
		action(philo);
		i++;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_tab	tab;

	init(&tab, ac, av);
	clean(&tab);
	return (0);
}
