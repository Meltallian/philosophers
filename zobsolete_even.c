/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obsolete_even.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:23:57 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/15 13:46:44 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	even_utils_2(t_philo *philo)
{
	printf("%ld %s has taken the fork %d\n", get_time_in_ms()
		- philo->tab->st, philo->name, philo->right_f);
	philo->state = 'e';
}

void	even_utils_3(t_philo *philo)
{
	if (philo->tab->n_f > 1)
		pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
	pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
}

int	even_utils(t_philo *philo)
{
	if (philo->tab->n_f > 1)
	{
		pthread_mutex_lock(&(philo->fork[philo->right_f].mutex));
		if (philo->state == 'r')
		{
			if (philo->tab->dead == 1)
			{
				pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
				pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
				return (0);
			}
			even_utils_2(philo);
		}
	}
	eating_assist(philo);
	if (philo->tab->dead == 1)
	{
		pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
		pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
		return (0);
	}
	even_utils_3(philo);
	return (1);
}

int	even_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork[philo->left_f].mutex));
	if (philo->state == 'f')
	{
		if (philo->tab->dead == 1)
		{
			pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
			return (0);
		}
		printf("%ld %s has taken the fork %d\n", get_time_in_ms()
			- philo->tab->st, philo->name, philo->left_f);
		philo->state = 'r';
	}
	return (even_utils(philo));
}
