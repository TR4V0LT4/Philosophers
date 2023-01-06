#include "../include/philo.h"

void *routine(void *data)
{
	t_philo *philo;
	philo = (t_philo *)data;

	if (philo->id % 2)
		ft_usleep(100);
	while (1)
	{ 
		pthread_mutex_lock(&(philo->data->god));
		 if (!philo->data->life)
		 {
		 	pthread_mutex_unlock(&(philo->data->god));
		 	break;
		 }
		pthread_mutex_unlock(&(philo->data->god));
		eat(philo); 
		wait_next_round(philo);	
	}
	return (NULL);
}

int eat(t_philo *philo)
{
		
		pthread_mutex_lock(&(philo->data->forks_mutex[philo->l_fork]));
			print_action(philo, "\033[30;1m has left fork\033[0m",get_time());
		pthread_mutex_lock(&(philo->data->forks_mutex[philo->r_fork]));
			print_action(philo, "\033[30;1m has right fork\033[0m", get_time());
		pthread_mutex_lock(&(philo->data->god));
			philo->data->philos[philo->id].eating = 1;
			philo->death_time = get_time() + philo->data->t_die;
		pthread_mutex_unlock(&(philo->data->god)); 
			print_action(philo, " eating.. 🍽️", get_time());
			ft_usleep(philo->data->t_eat );
		pthread_mutex_lock(&(philo->data->god));
			philo->data->philos[philo->id].eating = 0;
		pthread_mutex_unlock(&(philo->data->god));
		pthread_mutex_unlock(&(philo->data->forks_mutex[philo->r_fork]));
		pthread_mutex_unlock(&(philo->data->forks_mutex[philo->l_fork]));
		return 0;
}

int wait_next_round(t_philo *philo)
{
	print_action(philo, " sleeping 💤",get_time());
	ft_usleep(philo->data->t_sleep);
	print_action(philo, " thinking 🤔", get_time());
	return 0;
}
