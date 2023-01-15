/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:34:42 by wlahyani          #+#    #+#             */
/*   Updated: 2023/01/15 09:49:24 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	death_note(t_data *data)
{
	int	i;
	int	n;
	int	counter;
	int	meals;

	i = 0;
	n = 1;
	counter = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&(data->god));
		if (get_time() >= data->philos[i].death_time
			&& !(data->philos[i].eating))
			data->life = 0;
		n = data->life;
		meals = data->philos[i].number_of_meals;
		pthread_mutex_unlock(&(data->god));
		if (!meals)
			counter++;
		if (!n)
		{
			printf("%5zu      %d      %s\n",
				get_time() - data->start_time, data->philos[i].id, "dead");
			return (0);
		}
		else if (counter >= data->n_philos)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	t_data	*data;

	i = -1;
	data = malloc(sizeof(t_data));
	if (ac != 5 && ac != 6)
		return (printf("too many arguments\n"));
	if (!init_data(data, av))
	{
		init_mutexs(data);
		data->start_time = get_time();
		while (++i < data->n_philos)
		{
			if (init_philos(data, i, av))
				return (0);
			if (pthread_create(&(data->philos[i].philo), NULL
					, &routine, (void *)&(data->philos[i])))
				return (printf("failed creating thread\n"));
			if (pthread_detach(data->philos[i].philo))
				return (printf("failed detaching thread\n"));
				if(data->philos[i].id % 2)
					usleep(100);
		}
		while (death_note(data))
			usleep (200);
	}
	return (0);
}