/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:26:10 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/15 15:23:36 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	to_sleep(t_philo *philo)
{
	if (philo->state == 's')
	{
		printf("%ld %s is sleeping\n", get_time_in_ms()
			- philo->tab->st, philo->name);
		ft_usleep(philo->tab->t_sleep);
		philo->state = 't';
	}
}

void	to_think(t_philo *philo)
{
	if (philo->state == 't')
	{
		printf("%ld %s is thinking\n", get_time_in_ms()
			- philo->tab->st, philo->name);
		philo->state = 'f';
	}
}

int	eating_assist(t_philo *philo)
{
	if (philo->state == 'e')
	{
		printf("%ld %s is eating\n", get_time_in_ms()
			- philo->tab->st, philo->name);
		if (philo->tab->dead == 1)
			return (0);
		pthread_mutex_lock(&(philo->satiate));
		philo->satiated = get_time_in_ms();
		pthread_mutex_unlock(&(philo->satiate));
		philo->just_eaten = 1;
		philo->meals++;
		ft_usleep(philo->tab->t_eat);
		philo->state = 's';
	}
	return (1);
}

int	to_eat(t_philo *philo)
{
	if (philo->just_eaten == 0)
	{
		if (philo->id % 2 == 0)
		{
			return (even_eat(philo));
		}
		else
		{
			return (odd_eat(philo));
		}
	}
	return (1);
}

int	action(t_philo *philo)
{
	if (philo->tab->dead == 1)
		return (0);
	to_eat(philo);
	if (philo->tab->dead == 1)
		return (0);
	if (philo->meals == philo->tab->min_meal)
	{
		philo->state = 'o';
		pthread_mutex_lock(&(philo->satiate));
		philo->tab->full++;
		pthread_mutex_unlock(&(philo->satiate));
		return (0);
	}
	if (philo->tab->dead == 1)
		return (0);
	to_sleep(philo);
	if (philo->tab->dead == 1)
		return (0);
	to_think(philo);
	return (1);
}
