/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/07 15:25:32 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	to_eat(t_philo *philo)
{

	pthread_mutex_lock(&(philo->fork[philo->left_f].mutex));
	if (philo->state == 'f')
	{
		printf("%s has taken the fork %d\n", philo->name, philo->left_f);
		philo->state = 'r';
	}
	pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
	pthread_mutex_lock(&(philo->fork[philo->right_f].mutex));
	if (philo->state == 'r')
	{
		printf("%s has taken the fork %d\n", philo->name, philo->right_f);
		philo->state = 'e';
	}
	pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
}

void	action(t_philo *philo)
{
	to_eat(philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	action(philo);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_tab	tab;

	init(&tab, ac, av);
	clean(&tab);
	return (0);
}
