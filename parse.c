/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:43:42 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/06 14:58:09 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_philo(t_tab *tab, int ac)
{
	int	i;

	i = 0;
	while (i < tab->n_f)
		tab->ph[i++].state = 'f';
	i = 0;
	while (i < tab->n_f)
	{
		tab->ph[i].id = i;
		i++;
	}
	i = 0;
	while (i < tab->n_f && ac == 6)
		tab->ph[i++].meals = 0;
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
