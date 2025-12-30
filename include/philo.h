/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:12:06 by wlahyani          #+#    #+#             */
/*   Updated: 2023/01/15 19:25:07 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				eating;
	int				number_of_meals;
	size_t			death_time;
	struct s_data	*data;
	pthread_t		philo;

}	t_philo;

typedef struct s_data
{
	int					n_philos;
	int					life;
	size_t				t_die;
	size_t				t_eat;
	size_t				t_sleep;
	size_t				start_time;
	t_philo				*philos;
	pthread_mutex_t		*forks_mutex;
	pthread_mutex_t		print;
	pthread_mutex_t		god;
}	t_data;

void	guide(void);
void	ft_usleep(size_t n);
void	print_action(t_philo *philo, char *action, size_t t);
void	*routine(void *data);

int		init_philos(t_data *data, int i, char **av);
int		init_data(t_data *data, char **av);
int		init_mutexs(t_data *data);
int		init_philosophers(t_data *data);
int		wait_next_round(t_philo *philo);
int		eat(t_philo *philo);
int		check_args(char **av);

size_t	get_time(void);

#endif
