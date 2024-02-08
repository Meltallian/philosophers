/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:50:53 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/08 16:42:40 by jbidaux          ###   ########.fr       */
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
		i++;
	}
	free(tab->ph);
	free(tab->fork);
}

/* void	only_one_philo(char **av)
{
	if (av[1])
	{
		printf("There's only one fork, hence ")
	}
} */