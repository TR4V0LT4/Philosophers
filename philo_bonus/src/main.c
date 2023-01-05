#include "../include/philo_bonus.h"

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
			init_philos(&data,i);
            printf("philo[%d]\n",i);
		}
	}
	else 
		guide();
	return 0;
}