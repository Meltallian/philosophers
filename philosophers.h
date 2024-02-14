/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:29:26 by jbidaux           #+#    #+#             */
/*   Updated: 2024/02/14 17:00:01 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>

# define PP printf("prout")
# define DD(xxx) printf("%d\n", xxx)
# define SS(xxx) printf("%s\n", xxx)
# define CC(xxx) printf("%c\n", xxx)

typedef struct s_table	t_tab;

typedef struct s_fork
{
	int				id;
	char			state;
	pthread_mutex_t	mutex;
}			t_fork;

typedef struct s_philo
{
	pthread_t		p;
	int				id;
	int				left_f;
	int				right_f;
	const char		*name;
	char			state;
	int				meals;
	long			satiated;
	pthread_mutex_t	satiate;
	t_fork			*fork;
	t_tab			*tab;
}			t_philo;

typedef struct s_table
{
	t_philo			*ph;
	t_fork			*fork;
	int				n_f;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				min_meal;
	long			st;
	int				dead;
	int				full;
	pthread_mutex_t	running;
	pthread_t		p;
}			t_tab;

int		is_int(char **av, int ac);
int		init(t_tab *tab, int ac, char **av);
int		init_assist(t_tab *tab, int ac, char **av);
int		init_assist_2(t_tab *tab, int ac, char **av);
void	clean(t_tab *tab);
void	set_philo_helper(t_tab *tab, int ac);
void	set_philo(t_tab *tab, int ac);
void	set_fork(t_tab *tab);
void	name(t_tab *tab);
void	*philo_routine(void *arg);
int		threads(t_tab *tab);
long	get_time_in_ms();
void	*monitor_routine(void *arg);
int		ft_usleep(size_t milliseconds);
void	eating_assist(t_philo *philo);
void	to_sleep(t_philo *philo);
void	to_think(t_philo *philo);
int		to_eat(t_philo *philo);
int		action(t_philo *philo);
int		even_eat(t_philo *philo);
int		odd_eat(t_philo *philo);

#endif // PHILOSOPHERS_H