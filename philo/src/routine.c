/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:49:59 by wlahyani          #+#    #+#             */
/*   Updated: 2023/01/15 09:57:42 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		pthread_mutex_lock(&(philo->data->god));
		if (!philo->data->life || !philo->data->philos[philo->id].number_of_meals)
		{
			pthread_mutex_unlock(&(philo->data->god));
			break ;
		}
		pthread_mutex_unlock(&(philo->data->god));
		if (eat(philo))
			break ;
		wait_next_round(philo);
	}
	return (NULL);
}

int	eat(t_philo *philo)
{
	int	meals;

	pthread_mutex_lock(&(philo->data->forks_mutex[philo->l_fork]));
	print_action(philo, "has taken a fork", get_time());
	pthread_mutex_lock(&(philo->data->forks_mutex[philo->r_fork]));
	print_action(philo, "has taken a fork", get_time());
	pthread_mutex_lock(&(philo->data->god));
	philo->data->philos[philo->id].eating = 1;
	philo->death_time = get_time() + philo->data->t_die;
	meals = philo->number_of_meals--;
	pthread_mutex_unlock(&(philo->data->god));
	print_action(philo, "eating ", get_time());
	ft_usleep(philo->data->t_eat);
	pthread_mutex_lock(&(philo->data->god));
	philo->data->philos[philo->id].eating = 0;
	pthread_mutex_unlock(&(philo->data->god));
	pthread_mutex_unlock(&(philo->data->forks_mutex[philo->r_fork]));
	pthread_mutex_unlock(&(philo->data->forks_mutex[philo->l_fork]));
	if (!meals)
		return (1);
	return (0);
}

int	wait_next_round(t_philo *philo)
{
	print_action(philo, "sleeping ", get_time());
	ft_usleep(philo->data->t_sleep);
	print_action(philo, "thinking ", get_time());
	return (0);
}
