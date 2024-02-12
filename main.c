/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/12 10:31:33 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	to_sleep(t_philo *philo)
{
	if (philo->state == 's')
	{
		printf("%ld %s is sleeping\n", get_time_in_ms() -
			philo->tab->st, philo->name);
		usleep(philo->tab->t_sleep * 1000);
		philo->state = 't';
	}
}

void	to_think(t_philo *philo)
{
	if (philo->state == 't')
	{
		printf("%ld %s is thinking\n", get_time_in_ms() -
			philo->tab->st, philo->name);
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
			printf("%ld %s has taken the fork %d\n", get_time_in_ms() -
				philo->tab->st, philo->name, philo->left_f);
			philo->state = 'r';
		}
		pthread_mutex_lock(&(philo->fork[philo->right_f].mutex));
		if (philo->state == 'r')
		{
			printf("%ld %s has taken the fork %d\n", get_time_in_ms() -
				philo->tab->st, philo->name, philo->right_f);
			philo->state = 'e';
		}
		if (philo->state == 'e')
		{
			printf("%ld %s is eating\n", get_time_in_ms() -
				philo->tab->st, philo->name);
			philo->satiated = get_time_in_ms();
			usleep(philo->tab->t_eat * 1000);
			philo->meals++;
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
			printf("%ld %s has taken the fork %d\n", get_time_in_ms() -
				philo->tab->st, philo->name, philo->right_f);
			philo->state = 'r';
		}
		pthread_mutex_lock(&(philo->fork[philo->left_f].mutex));
		if (philo->state == 'r')
		{
			printf("%ld %s has taken the fork %d\n", get_time_in_ms() -
				philo->tab->st, philo->name, philo->left_f);
			philo->state = 'e';
		}
		if (philo->state == 'e')
		{
			printf("%ld %s is eating\n", get_time_in_ms() -
				philo->tab->st, philo->name);
			philo->satiated = get_time_in_ms();
			usleep(philo->tab->t_eat * 1000);
			philo->meals++;
			philo->state = 's';
		}
		pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
		pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
	}
}

int	action(t_philo *philo)
{
	long		time_ms;
	long		since_last_meal_ms;

	to_eat(philo);
	if (philo->meals == philo->tab->min_meal)
		return (10);
	to_sleep(philo);
	time_ms = get_time_in_ms();
	since_last_meal_ms = time_ms - philo->satiated;
	if (since_last_meal_ms >= philo->tab->t_die)
	{
		printf("%ld %s died\n", get_time_in_ms() -
			philo->tab->st, philo->name);
		return (10) ;
	}
	to_think(philo);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->satiated = get_time_in_ms();
	philo->tab->st = get_time_in_ms();
	while (1)
	{
		if (action(philo) == 10)
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
