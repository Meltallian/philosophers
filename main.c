/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/07 14:06:32 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	to_eat(t_philo *philo)
{
	if (philo->state == 'f')
	{
		printf("%s has taken the fork %d\n", philo->name, philo->left_f);
		philo->state = 'r';
	}
	if (philo->state == 'r')
	{
		printf("%s has taken the fork %d\n", philo->name, philo->right_f);
		philo->state = 'e';
	}
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
// for (int i = 0; i < philo->tab->n_f; i++) {
//     printf("Philosopher %d is named %s\n", i, philo->tab->ph[i].name ? philo->tab->ph[i].name : "NULL");
// }

	return (NULL);
}

int	main(int ac, char **av)
{
	t_tab	tab;

	init(&tab, ac, av);
	clean(&tab);
	return (0);
}
