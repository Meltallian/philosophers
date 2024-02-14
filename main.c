/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/14 16:26:41 by jbidaux          ###   ########.fr       */
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

int	to_eat(t_philo *philo)
{
	usleep(1000);
	if (philo->tab->dead == 1)
		return (0);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&(philo->fork[philo->left_f].mutex));
		if (philo->state == 'f')
		{
			if (philo->tab->dead == 1)
			{
				pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
				return (0);
			}
			printf("%ld %s has taken the fork %d\n", get_time_in_ms() -
				philo->tab->st, philo->name, philo->left_f);
			philo->state = 'r';
		}
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
				printf("%ld %s has taken the fork %d\n", get_time_in_ms() -
					philo->tab->st, philo->name, philo->right_f);
				philo->state = 'e';
			}
		}
		if (philo->tab->dead == 1)
		{
			pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
			pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
			return (0);
		}
		if (philo->state == 'e')
		{
			printf("%ld %s is eating\n", get_time_in_ms() -
				philo->tab->st, philo->name);
			pthread_mutex_lock(&(philo->satiate));
			philo->satiated = get_time_in_ms();
			pthread_mutex_unlock(&(philo->satiate));
			usleep(philo->tab->t_eat * 1000);
			philo->meals++;
			philo->state = 's';
		}
		if (philo->tab->n_f > 1)
			pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
		pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
		if (philo->tab->dead == 1)
			return (0);
	}
	else
	{
		pthread_mutex_lock(&(philo->fork[philo->right_f].mutex));
		if (philo->state == 'f')
		{
			if (philo->tab->dead == 1)
			{
				pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
				return (0);
			}
			printf("%ld %s has taken the fork %d\n", get_time_in_ms() -
				philo->tab->st, philo->name, philo->right_f);
			philo->state = 'r';
		}
		pthread_mutex_lock(&(philo->fork[philo->left_f].mutex));
		if (philo->state == 'r')
		{
			if (philo->tab->dead == 1)
			{
				pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
				pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
				return (0);
			}
			printf("%ld %s has taken the fork %d\n", get_time_in_ms() -
				philo->tab->st, philo->name, philo->left_f);
			philo->state = 'e';
		}
		if (philo->tab->dead == 1)
		{
			pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
			pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
			return (0);
		}
		if (philo->state == 'e')
		{
			printf("%ld %s is eating\n", get_time_in_ms() -
				philo->tab->st, philo->name);
			pthread_mutex_lock(&(philo->satiate));
			philo->satiated = get_time_in_ms();
			pthread_mutex_unlock(&(philo->satiate));
			usleep(philo->tab->t_eat * 1000);
			philo->meals++;
			philo->state = 's';
		}
		pthread_mutex_unlock(&(philo->fork[philo->right_f].mutex));
		pthread_mutex_unlock(&(philo->fork[philo->left_f].mutex));
		if (philo->tab->dead == 1)
			return (0);
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

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->satiated = get_time_in_ms();
	while (1)
	{
		if (philo->tab->dead == 1 ||  get_time_in_ms() - philo->satiated >= philo->tab->t_die)
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
		if (get_time_in_ms() - tab->ph[i].satiated >= tab->t_die)
		{
			printf("%ld %s died\n", get_time_in_ms() -
				tab->st, tab->ph[i].name);
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
