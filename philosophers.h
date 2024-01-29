/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:26 by jbidaux           #+#    #+#             */
/*   Updated: 2024/01/29 16:17:29 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>

# define PP ft_printf("prout")
# define DD(xxx) ft_printf("%d", xxx)
# define SS(xxx) ft_printf("%s", xxx)
# define CC(xxx) ft_printf("%c", xxx)

typedef struct s_philo
{
	int	id;
}			t_philo;

typedef struct s_table
{
	t_philo	*ph;
	int		fork;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		min_meal;
}			t_tab;

void	is_int(char **av, int ac);

#endif // PHILOSOPHERS_H