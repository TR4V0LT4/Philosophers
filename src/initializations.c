#include "../include/philo.h"
int fill_data(t_data *data, char **av)
{
		int n;
		n = atoi(av[1]);	
		if (n > 200 || n < 2)
				return (printf("invalide number of philos\n"));
		data->n_philos = n;
		data->t_die = atoi(av[2]);
		data->t_eat = atoi(av[3]);
		data->t_sleep = atoi(av[4]);
		data->life = 1;
		if(check_args(av))
			return(1);
		data->philos = malloc(sizeof(t_philo) * n);
		data->forks_mutex = malloc(sizeof(pthread_mutex_t) * n);
		if (!data->philos || !data->forks_mutex)
				return (printf("allocation failed"));
		return 0;
}

int init_mutexs(t_data *data)
{
		int i;
		i = 0;
		while (i < data->n_philos)
		{
				pthread_mutex_init(&(data->forks_mutex[i]), NULL);
				i++;
		}
		pthread_mutex_init(&(data->print), NULL);
		pthread_mutex_init(&(data->god), NULL);
		pthread_mutex_init(&(data->imad),NULL);
		return 0;
}

void init_philos(t_data *data,int i)
{
		data->philos[i].id = i;
		data->philos[i].l_fork = i;
		data->philos[i].r_fork = (i + 1) % data->n_philos;
		data->philos[i].data = data; 
		data->philos[i].death_time = get_time() + data->t_die;
}