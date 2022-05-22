/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_times.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:19:44 by rsaf              #+#    #+#             */
/*   Updated: 2022/05/10 15:20:06 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

int	check_data_bonus(t_data *data)
{
	if (data->info.n_philos > 200 || data->info.n_philos <= 0)
		return (printf("Error: More or less then Allowd Philos"), 1);
	if (data->info.t_die < 60)
		return (printf("Error: Time to Die isn't Correct\n"), 1);
	if (data->info.t_eat < 60)
		return (printf("Error: Time to Eat isn't Correct\n"), 1);
	if (data->info.t_sleep < 60)
		return (printf("Error: Time to Sleep isn't Correct\n"), 1);
	if (data->ac == 6)
	{
		if (data->info.t_must_eat <= 0)
			return (printf("Error: must eat is less then 0\n"), 1);
	}
	return (0);
}
