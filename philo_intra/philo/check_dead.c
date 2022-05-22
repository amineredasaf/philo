/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 02:55:24 by rsaf              #+#    #+#             */
/*   Updated: 2022/05/20 02:55:28 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	is_dead(t_data *data, int idx)
{
	data->dead++;
	pthread_mutex_lock(&data->write_m);
	printf("[%lld]", time_now() - data->philo[idx].t_born);
	printf(" philo %d is dead\n", data->philo[idx].id);
}

int	check_dead(t_data *data)
{
	int	idx;
	int	must_eat;

	must_eat = data->info.n_philos * data->info.t_must_eat;
	idx = 0;
	while (!data->dead)
	{
		idx = 0;
		while (idx < data->info.n_philos)
		{
			if (data->ac == 6 && data->total_eat == must_eat)
			{
				data->dead++;
				pthread_mutex_lock(&data->write_m);
				break ;
			}
			if ((time_now() - data->philo[idx].l_meal >= data->info.t_die))
			{
				is_dead(data, idx);
				break ;
			}
			idx++;
		}
	}
	return (1);
}
