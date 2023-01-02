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
	int 			id;
	int 			l_fork;
	int 			r_fork;
	int				eating;
	size_t			alarme;
	size_t 			death_time;
	struct s_data 	*data;
	pthread_t 		philo;

} t_philo;

typedef struct s_data
{
	int				n_philos;
	int 			life;
	size_t		t_die;
	size_t		t_eat;
	size_t 		t_sleep;
	size_t 			start_time;
	t_philo 		*philos;
	pthread_mutex_t *forks_mutex;
	pthread_mutex_t print;
	pthread_mutex_t god;
	pthread_mutex_t imad;
} t_data;


void guide();
size_t get_time(void);
int fill_data(t_data *data, char **av);
void init_philos(t_data *data,int i);
int init_mutexs(t_data *data);
void *routine(void *data);
int init_philosophers(t_data *data);
void *routine(void *data);
int destroy_mutexs(t_data *data);
int think(t_philo *philo);
int eat(t_philo *philo);
int check_args(char **av);
void	ft_usleep(size_t n);
void print_action(t_philo *philo, char *action,size_t t);







#endif