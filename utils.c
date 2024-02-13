/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:50:53 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/13 15:04:02 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_int(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] > 57 || av[i][j] < 48)
			{
				printf("wrong syntax");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	clean(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->n_f)
	{
		pthread_mutex_destroy(&(tab->fork[i].mutex));
		pthread_mutex_destroy(&(tab->ph[i].satiate));
		i++;
	}
	pthread_mutex_destroy(&(tab->running));
	free(tab->ph);
	free(tab->fork);
}

long get_time_in_ms()
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000L + current_time.tv_usec / 1000);
}

// Improved version of sleep function
int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}