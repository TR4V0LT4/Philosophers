#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_philo
{
	int 			id;
	int 			l_fork;
	int 			r_fork;
	int				eating;
	size_t 			death_time;
	struct s_data 	*data;
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
} t_data;

int init_data(t_data *data, char **av);
void init_philos(t_data *data,int i);
void guide();
size_t get_time(void);
void	ft_usleep(size_t n);
int	ft_isdigit(int c);
int check_args(char **av);

#endif