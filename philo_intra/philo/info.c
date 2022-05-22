/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:16:55 by rsaf              #+#    #+#             */
/*   Updated: 2022/05/10 15:17:47 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	info(t_data *data)
{
	printf("Number of Philo :\t\t%d\n", data->info.n_philos);
	printf("Time To eat     :\t\t%d\n", data->info.t_eat);
	printf("Time to die     :\t\t%d\n", data->info.t_die);
	printf("Time to sleep   :\t\t%d\n", data->info.t_sleep);
	printf("Time to sleep   :\t\t%d\n", data->info.t_sleep);
	printf("Time to sleep   :\t\t%d\n", data->info.t_sleep);
	if (data->ac == 6)
		printf("Time to must eat:\t\t%d\n", data->info.t_must_eat);
}
