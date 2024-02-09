/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/09 11:53:55 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	to_sleep(t_philo *philo)
{
	struct timeval	time;

	if (philo->state == 's')
	{
		gettimeofday(&time, NULL);
		printf("%ld %s is sleeping\n", (time.tv_sec * 1000 - philo->tab->start.tv_sec * 1000) +
			(time.tv_usec / 1000 - philo->tab->start.tv_usec / 1000), philo->name);
		usleep(philo->tab->t_sleep * 1000);
		philo->state = 't';
	}
}

void	to_think(t_philo *philo)
{
	struct timeval	time;

	if (philo->state == 't')
	{
		gettimeofday(&time, NULL);
		printf("%ld %s is thinking\n", (time.tv_sec * 1000 - philo->tab->start.tv_sec * 1000) +
			(time.tv_usec / 1000 - philo->tab->start.tv_usec / 1000), philo->name);
		philo->state = 'f';
	}
}

void	to_eat(t_philo *philo)
{
	struct timeval	time;

	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&(philo->fork[philo->left_f].mutex));
		if (philo->state == 'f')
		{
			gettimeofday(&time, NULL);
			printf("%ld %s has taken the fork %d\n", (time.tv_sec * 1000 - philo->tab->start.tv_sec * 1000) +
				(time.tv_usec / 1000 - philo->tab->start.tv_usec / 1000), philo->name, philo->left_f);
			philo->state = 'r';
		}
		pthread_mutex_lock(&(philo->fork[philo->right_f].mutex));
		if (philo->state == 'r')
		{
			gettimeofday(&time, NULL);
			printf("%ld %s has taken the fork %d\n", (time.tv_sec * 1000 - philo->tab->start.tv_sec * 1000) +
				(time.tv_usec / 1000 - philo->tab->start.tv_usec / 1000), philo->name, philo->right_f);
			philo->state = 'e';
		}
		if (philo->state == 'e')
		{
			gettimeofday(&time, NULL);
			printf("%ld %s is eating\n", (time.tv_sec * 1000 - philo->tab->start.tv_sec * 1000) +
				(time.tv_usec / 1000 - philo->tab->start.tv_usec / 1000), philo->name);
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
			gettimeofday(&time, NULL);
			printf("%ld %s has taken the fork %d\n", (time.tv_sec * 1000 - philo->tab->start.tv_sec * 1000) +
				(time.tv_usec / 1000 - philo->tab->start.tv_usec / 1000), philo->name, philo->right_f);
			philo->state = 'r';
		}
		pthread_mutex_lock(&(philo->fork[philo->left_f].mutex));
		if (philo->state == 'r')
		{
			gettimeofday(&time, NULL);
			printf("%ld %s has taken the fork %d\n", (time.tv_sec * 1000 - philo->tab->start.tv_sec * 1000) +
				(time.tv_usec / 1000 - philo->tab->start.tv_usec / 1000), philo->name, philo->left_f);
			philo->state = 'e';
		}
		if (philo->state == 'e')
		{
			gettimeofday(&time, NULL);
			printf("%ld %s is eating\n", (time.tv_sec * 1000 - philo->tab->start.tv_sec * 1000) +
				(time.tv_usec / 1000 - philo->tab->start.tv_usec / 1000), philo->name);
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
	struct timeval	start_time;
	struct timeval	end_time;
	//int				time_wo_food;

	gettimeofday(&end_time, NULL);
/* 	time_wo_food = (end_time.tv_usec / 1000) - (start_time.tv_usec / 1000);
	if (time_wo_food > philo->tab->t_die)
	{
		printf("%ld %s died\n", end_time.tv_usec / 1000, philo->name);
		exit (1);
	} */
	to_eat(philo);
	if (philo->meals == philo->tab->min_meal)
		return (10);
	gettimeofday(&start_time, NULL);
	to_sleep(philo);
	to_think(philo);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
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
