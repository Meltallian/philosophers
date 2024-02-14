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

void	eating_assist(t_philo *philo)
{
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
}

int	to_eat(t_philo *philo)
{
	usleep(1000);
	if (philo->id % 2 == 0)
		return(even_eat(philo));
	else
		return(odd_eat(philo));
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
