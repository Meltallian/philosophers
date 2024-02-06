/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:20 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/06 16:31:32 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	to_eat(t_tab *tab)
{

}

void	grab_fork(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->min_meal)
	{
		pthread_mutex_lock(&(tab->fork[i].mutex));
		if ((tab->ph[i].state == 'f' || tab->ph[i].state == 'r') &&
			(tab->fork[i].id == tab->ph[i].id || tab->fork[i].id == tab->ph[i].id + 1) &&
			tab->fork[i].state == 'f' && tab->fork[i + 1].state == 'f')
		{
			printf("%s has taken the fork %d\n", tab->ph[i].name, tab->fork[i].id);
			if (tab->ph[i].state == 'r')
				tab->ph[i].state = 'e';
			if (tab->ph[i].state == 'f')
				tab->ph[i].state = 'r';
			tab->fork[i].state = 't';
		}

		if ((tab->ph[tab->n_f - 1].state == 'f' || tab->ph[tab->n_f - 1].state == 'r') &&
			(tab->fork[i].id == tab->ph[tab->n_f - 1].id || tab->fork[0].id == tab->ph[tab->n_f - 1].id) &&
			tab->fork[i].state == 'f')
		{
			printf("%s has taken the fork %d\n", tab->ph[i].name, tab->fork[i].id);
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
			tab->fork[i].state = 'f';
			if (tab->ph[i].id == tab->n_f - 1)
				tab->fork[0].state = 'f';
			if (tab->ph[i].id != tab->n_f - 1)
				tab->fork[i + 1].state = 'f';
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
