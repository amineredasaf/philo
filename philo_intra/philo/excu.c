/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:16:25 by rsaf              #+#    #+#             */
/*   Updated: 2022/05/10 15:16:40 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_frk);
	print_state(philo, "Has take the left fork");
	pthread_mutex_lock(philo->righ_frk);
	print_state(philo, "Has take the right fork");
	print_state(philo, "is eating");
	philo->l_meal = time_now();
	resting(philo->dta->info.t_eat, philo);
	pthread_mutex_lock(&philo->dta->eating_m);
	philo->dta->total_eat++;
	philo->total_m++;
	pthread_mutex_unlock(&philo->dta->eating_m);
	pthread_mutex_unlock(philo->left_frk);
	pthread_mutex_unlock(philo->righ_frk);
}

void	*routine(void *ptr)
{
	int		idx;
	t_philo	*philo;

	idx = 0;
	philo = (t_philo *)ptr;
	philo->l_meal = time_now();
	while (!philo->dta->dead && philo->total_m != philo->dta->info.t_must_eat)
	{
		is_eating(philo);
		print_state(philo, "is sleeping");
		resting(philo->dta->info.t_sleep, philo);
		print_state(philo, "is thinking");
	}
	return (0);
}

int	create_threads(t_data *data)
{
	int	x;
	int	e;
	int	nb_of_philo;

	x = 0;
	e = 0;
	nb_of_philo = data->info.n_philos;
	while (x < nb_of_philo)
	{
		data->philo[x].t_born = time_now();
		e = pthread_create(&data->thread[x], NULL, &routine, &data->philo[x]);
		if (e != 0)
			return (printf("Error: pthread create problem\n"), 1);
		usleep(100);
		x++;
	}
	check_dead(data);
	return (0);
}

int	destroy_program(t_data *data)
{
	int	idx;
	int	nb_of_philo;

	idx = 0;
	nb_of_philo = data->info.n_philos;
	while (idx < nb_of_philo && !(data->dead))
	{
		if (pthread_join(data->thread[idx], NULL) != 0)
			return (printf("Error: pthread join problem\n"), 1);
		idx++;
	}
	idx = 0;
	while (idx < data->info.n_philos)
	{
		pthread_mutex_destroy(&data->info.forks_m[idx]);
		idx++;
	}
	pthread_mutex_destroy(&data->write_m);
	return (0);
}

int	excu(t_data *data)
{
	int	idx;
	int	nb_of_philo;

	idx = 0;
	data->dead = 0;
	data->total_eat = 0;
	nb_of_philo = data->info.n_philos;
	if (data != NULL)
	{
		if (init_mutex(data) == 1)
			return (1);
		init_philo(data);
		if (create_threads(data) == 1)
			return (1);
		if (destroy_program(data) == 1)
			return (1);
	}
	return (0);
}
