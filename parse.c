/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:43:42 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/07 11:37:16 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_philo_helper(t_tab *tab, int ac)
{
	int	i;

	i = 0;
	while (i < tab->n_f)
	{
		tab->ph[i].state = 'f';
		i++;
	}
	i = 0;
	while (i < tab->n_f)
	{
		tab->ph[i].id = i;
		tab->ph[i].left_f = i;
		tab->ph[i].tab = tab;
		i++;
	}
	i = 0;
	while (i < tab->n_f && ac == 6)
	{
		tab->ph[i].meals = 0;
		i++;
	}
}

void	set_philo(t_tab *tab, int ac)
{
	int	i;

	i = 0;
	set_philo_helper(tab, ac);
	while (i < tab->n_f - 1)
	{
		tab->ph[i].right_f = i + 1;
		i++;
	}
	tab->ph[i].right_f = 0;
}

void	set_fork(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->n_f)
	{
		tab->fork[i].id = i;
		i++;
	}
	i = 0;
	while (i < tab->n_f)
	{
		tab->fork[i].state = 'f';
		i++;
	}
}
