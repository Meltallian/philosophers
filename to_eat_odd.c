#include "philosophers.h"

void	odd_assist_2(t_philo *philo)
{
	printf("%ld %s has taken the fork %d\n", get_time_in_ms() -
		philo->tab->st, philo->name, philo->left_f);
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
	eating_assist(philo);
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
		printf("%ld %s has taken the fork %d\n", get_time_in_ms() -
			philo->tab->st, philo->name, philo->right_f);
		philo->state = 'r';
	}
	pthread_mutex_lock(&(philo->fork[philo->left_f].mutex));
	return (odd_assist(philo));
}
