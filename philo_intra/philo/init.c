/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:42:02 by rsaf              #+#    #+#             */
/*   Updated: 2022/05/19 18:42:05 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long long	time_now(void)
{
	struct timeval	te;

	gettimeofday(&te, NULL);
	return ((te.tv_sec * 1000) + te.tv_usec / 1000);
}

int	init_mutex(t_data *data)
{
	int	e;
	int	idx;
	int	nb_of_philo;

	idx = 0;
	e = 0;
	nb_of_philo = data->info.n_philos;
	data->info.forks_m = malloc(sizeof(pthread_mutex_t *) * nb_of_philo);
	if (!data->info.forks_m)
		return (printf("Error: Malloc error\n"), 1);
	while (idx < data->info.n_philos)
	{
		e = pthread_mutex_init(&data->info.forks_m[idx], NULL);
		if (e != 0)
			return (printf("Error: mutex init problem\n"), 1);
		idx++;
	}
	if (pthread_mutex_init(&data->eating_m, NULL) != 0)
		return (printf("Error: mutex init problem\n"), 1);
	if (pthread_mutex_init(&data->write_m, NULL) != 0)
		return (printf("Error: mutex init problem\n"), 1);
	return (0);
}

void	init_philo(t_data *data)
{
	int	idx;
	int	nb_of_philo;

	idx = 0;
	nb_of_philo = data->info.n_philos;
	while (idx < data->info.n_philos)
	{
		data->philo[idx].id = idx + 1;
		data->philo[idx].t_born = time_now();
		data->philo[idx].left_frk = &data->info.forks_m[idx];
		if (idx == nb_of_philo - 1)
			data->philo[idx].righ_frk = &data->info.forks_m[0];
		else
			data->philo[idx].righ_frk = &data->info.forks_m[idx + 1];
		data->philo[idx].dta = data;
		idx++;
	}
}
