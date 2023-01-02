#include "philo.h"
void guide()
{
	printf("Put four arguments the fifth is optional :\n");
	printf(" ==>First  : [number_of_philosofers]\n");
	printf(" ==>Second : [time_to_die]\n");
	printf(" ==>Third  : [time_to_eat]\n");
	printf(" ==>fourth : [time_to_sleep]\n");
	printf(" ==>Fifth  : [the_number_of_meals]\n");
}

size_t get_time(void)
{
	static struct timeval t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep(size_t n)
{
	size_t end = n + get_time();
	while (1)
	{
		if (end <= get_time())
			break ;
		usleep(50);
	}
}

void print_action(t_philo *philo, char *action,size_t t)
{
	pthread_mutex_lock(&(philo->data->print));
		printf("\033[36;1mPhilo[%d] : %5zu ==>\033[0m%s\n",philo->id,t - philo->data->start_time, action);
	pthread_mutex_unlock(&(philo->data->print));
}

int destroy_mutexs(t_data *data)
{
	while(data->n_philos--)
	pthread_mutex_destroy(data->forks_mutex);
	pthread_mutex_destroy(&(data->print));
	pthread_mutex_destroy(&(data->god));
	return 0;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int check_args(char **av)
{
	int i = 1;
	int j = 0;

	while(av[i])
	{
		j=-1;
		while(av[i][++j])
			if(!ft_isdigit(av[i][j]))
			{
				return(printf("wrong args type\n"));
				guide();
			}
		i++;
	}
	return 0;
}
