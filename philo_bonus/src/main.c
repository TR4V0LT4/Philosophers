#include "../include/philo_bonus.h"
void death(t_data *data)
{
	int i  = 0;
	int n = 1;
	while(n)
	{
		i = 0;
		while(i < data->n_philos )
		{
			sem_wait(&(data->god));
				if( get_time() >= data->philos[i].death_time && !(data->philos[i].eating) ) 
					data->life = 0;
				n = data->life;
			sem_post(&(data->god));
			if(!n)
			{
				printf("Philo[%d] : %5zu ==> %s\n",data->philos[i].id, get_time() - data->start_time ,"  💀 dead 💀 ");
				break;
			}
			i++;
		}
	}
}
void eat(t_data *data)
{
	print_action(data," has taken both forks...",get_time());	
	data->philos[data->philos->id].eating = 1;
	data->philos[data->philos->id].death_time = get_time() + data->t_die;;
	print_action(data," eating.. 🍽️",get_time());
	ft_usleep(data->t_eat);
	data->philos[data->philos->id].eating = 0;
}
void routine(t_data *data)
{
	if(data->philos->id % 2)
		ft_usleep(100);
	eat(data);
	
	print_action(data," sleeping 💤",get_time());
		ft_usleep(data->t_sleep);
	print_action(data," thinking 🤔",get_time());

}
int main(int ac , char **av)
{
    t_data data;
	int i;

	i = -1;
	if ((ac == 5 || ac == 6) && !init_data(&data,av))
	{	
		sem_init(&(data.god),1,1);
		sem_init(&(data.print),1,1);
		data.start_time = get_time();
		while (++i < data.n_philos)
		{
			data.philos[i].id = i;
			data.philos[i].death_time = get_time() + data.t_die;
			data.pids[i] = fork();
			if(data.pids[i] == -1)
				return(printf("failed creating process"));
			if(data.pids[i] == 0)
			{
				routine(&data);
				break;
			}     
		}
		i = -1;
		while(++i < data.n_philos)
			wait(NULL);
	}
	else 
		guide();
	sem_destroy(&(data.god));
	sem_destroy(&(data.print));
	return 0;
}