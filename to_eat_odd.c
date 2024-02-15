/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_eat_odd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:26:25 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/15 14:54:39 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	odd_assist_2(t_philo *philo)
{
	printf("%ld %s has taken a fork\n", get_time_in_ms()
		- philo->tab->st, philo->name);
	philo->state = 'e';
}

int	odd_assist(t_philo *philo)
{
	if (philo->state == 'r')
	{
		if (philo->tab->dead == 1)
		{
			pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
			pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
			return (0);
		}
		odd_assist_2(philo);
	}
	if (philo->tab->dead == 1)
	{
		pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
		pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
		return (0);
	}
	if (eating_assist(philo) == 0)
		return (0);
	pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
	pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
	return (1);
}

int	odd_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork[philo->right_f].mutex));
	if (philo->state == 'f')
	{
		if (philo->tab->dead == 1)
		{
			pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
			return (0);
		}
		printf("%ld %s has taken a fork\n", get_time_in_ms()
			- philo->tab->st, philo->name);
		philo->state = 'r';
	}
	pthread_mutex_lock(&(philo->fork[philo->left_f].mutex));
	return (odd_assist(philo));
}
