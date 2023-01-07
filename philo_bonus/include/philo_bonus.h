#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <time.h>
# include <sys/time.h>
# include <sys/wait.h>
#include <semaphore.h>

typedef struct s_philo
{
	int 			id;
	int				eating;
	size_t 			death_time;
} t_philo;

typedef struct s_data
{
	int			*pids;
	int			n_philos;
	int 		life;
	size_t 		death_time;
	size_t 		start_time;
	size_t		t_die;
	size_t		t_eat;
	size_t 		t_sleep;
	t_philo		*philos;
	sem_t		god;
	sem_t		print;
} t_data;

void	guide();
void	ft_usleep(size_t n);
void print_action(t_data *data, char *action,size_t t);

int	init_data(t_data *data, char **av);
int	ft_isdigit(int c);
int	check_args(char **av);

size_t	get_time(void);

#endif