/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 08:58:22 by wlahyani          #+#    #+#             */
/*   Updated: 2023/01/15 19:05:12 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_data(t_data *data, char **av)
{
	data->n_philos = atoi(av[1]);
	if (data->n_philos > 200 || !data->n_philos)
		return (1);
	data->t_die = atoi(av[2]);
	data->t_eat = atoi(av[3]);
	data->t_sleep = atoi(av[4]);
	data->life = 1;
	if (check_args(av))
		return (printf("invalid argument\n"));
	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->philos || !data->forks_mutex)
		return (printf("failed allocation"));
	return (0);
}

int	init_mutexs(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_init(&(data->forks_mutex[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(data->print), NULL);
	pthread_mutex_init(&(data->god), NULL);
	return (0);
}

int	init_philos(t_data *data, int i, char **av)
{
	data->philos[i].id = i;
	data->philos[i].l_fork = i;
	data->philos[i].r_fork = (i + 1) % data->n_philos;
	data->philos[i].eating = 0;
	data->philos[i].data = data;
	data->philos[i].death_time = get_time() + data->t_die;
	if (av[5])
	{
		data->philos[i].number_of_meals = atoi(av[5]);
		if (!data->philos[i].number_of_meals)
			return (1);
	}
	else
		data->philos[i].number_of_meals = -1;
	return (0);
}
