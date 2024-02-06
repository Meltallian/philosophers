/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/06 11:57:05 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	grab_fork(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->n_f)
	{
		pthread_mutex_lock(&(tab->fork[i].mutex));
		if (tab->ph[i].state == 'f' || tab->ph[i].state == 'r')
		{
			printf("%s has taken a fork\n", tab->ph[i].name);
			if (tab->ph[i].state == 'r')
				tab->ph[i].state = 'e';
			if (tab->ph[i].state == 'f')
				tab->ph[i].state = 'r';
		}
		pthread_mutex_unlock(&(tab->fork[i].mutex));
		if (tab->ph[i].state == 'e')
		{
			printf("%s is eating\n", tab->ph[i].name);
			tab->ph[i].state = 's';
		}
		if (tab->ph[i].state == 's')
		{
			printf("%s is sleeping\n", tab->ph[i].name);
			tab->ph[i].state = 't';
		}
		if (tab->ph[i].state == 't')
		{
			printf("%s is thinking\n", tab->ph[i].name);
			tab->ph[i].state = 'f';
		}
		i++;
	}
}

void	*routine(void *arg)
{
	t_tab	*tab;

	tab = (t_tab *)arg;
	grab_fork(tab);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_tab	tab;

	init(&tab, ac, av);
	clean(&tab);
	return (0);
}
