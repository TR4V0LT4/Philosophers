/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:57:50 by wlahyani          #+#    #+#             */
/*   Updated: 2023/01/15 19:11:46 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h"

size_t	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep(size_t n)
{
	size_t	end;

	end = n + get_time();
	while (1)
	{
		usleep(50);
		if (end <= get_time())
			break ;
	}
}

void	print_action(t_philo *philo, char *action, size_t t)
{
	pthread_mutex_lock(&(philo->data->god));
	if (philo->data->life)
	{
		pthread_mutex_lock(&(philo->data->print));
		printf("%5zu    %3d     %s\n",
			t - philo->data->start_time, philo->id, action);
		pthread_mutex_unlock(&(philo->data->print));
	}
	pthread_mutex_unlock(&(philo->data->god));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = -1;
		if (!av[i][0])
			return (1);
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				return (1);
		i++;
	}
	return (0);
}
