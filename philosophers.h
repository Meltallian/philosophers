/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:26 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/02 16:51:38 by jbidaux          ###   ########.fr       */
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
# include <pthread.h>

# define PP printf("prout")
# define DD(xxx) printf("%d", xxx)
# define SS(xxx) printf("%s", xxx)
# define CC(xxx) printf("%c", xxx)

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}			t_fork;

typedef struct s_philo
{
	pthread_t		p;
	int				id;
	char			*name;
	char			state;
	int				meals;
}			t_philo;

typedef struct s_table
{
	t_philo		*ph;
	t_fork		*fork;
	int			n_f;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			min_meal;
}			t_tab;

void	is_int(char **av, int ac);
void	init(t_tab *tab, int ac, char **av);
void	init_assist(t_tab *tab, int ac, char **av);
void	clean(t_tab *tab);
void	set_philo(t_tab *tab, int ac);
void	set_fork(t_tab *tab);
void	name(t_tab *tab);

#endif // PHILOSOPHERS_H