#include "../include/philo.h"

void death_note(t_data *data)
{
	int i  = 0;
	int n = 1;
	while(n)
	{
		i = 0;
		while(i < data->n_philos && n )
		{
			pthread_mutex_lock(&(data->god));
			if( get_time() > data->philos[i].death_time && !(data->philos[i].eating) ) 
			{	
				printf("Philo[%d] : %5zu ==> %s\n",data->philos[i].id, get_time() - data->start_time ,"  💀 dead 💀 ");
				data->life = 0;
				printf("im heeeeeeeeeeeere");
				exit(1);
				n = 0;
		    }
			pthread_mutex_unlock(&(data->god));
			i++;
		}
	}
	return ;
}

int main(int ac, char **av)
{
	t_data data;
	int i;

	i = -1;
	if ((ac == 5 || ac == 6) && !fill_data(&data,av))
	{
		init_mutexs(&data);
		data.start_time = get_time();
		while (++i < data.n_philos)
		{
			init_philos(&data,i);
			if (pthread_create(&(data.philos[i].philo), NULL, &routine, (void *)&(data.philos[i])))
				return (printf("failed creating thread"));
		}
		death_note(&data);
			i = -1;
		while(++i < data.n_philos)
			if(pthread_join(data.philos[i].philo,NULL))
				return (printf("failed joining thread"));
	}
	else 
		guide();
	return 0;
}
