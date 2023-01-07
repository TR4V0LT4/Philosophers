#include "../include/philo_bonus.h"

int init_data(t_data *data, char **av)
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
		data->pids = malloc(sizeof(int) * n);
		return 0;
}
// void init_philos(t_data *data,int i)
// {
// 		data->philos[i].id = i;
// 		data->philos[i].l_fork = i;
// 		data->philos[i].r_fork = (i + 1) % data->n_philos;
// 		data->philos[i].data = data; 
// 		data->philos[i].death_time = get_time() + data->t_die;
// }