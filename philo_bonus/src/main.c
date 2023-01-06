#include "../include/philo_bonus.h"

void routine(t_data *data)
{
//	t_philo *philo;
//	philo = (t_philo *)data;

	printf("hello from pid = %d\n",data->pids[data->id]);
}
int main(int ac , char **av)
{
    t_data data;
	int i;

	i = -1;
	if ((ac == 5 || ac == 6) && !init_data(&data,av))
	{
		data.start_time = get_time();
		while (++i < data.n_philos)
		{
			data.id = i;
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
	return 0;
}