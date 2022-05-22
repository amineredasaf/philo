/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:25:58 by rsaf              #+#    #+#             */
/*   Updated: 2022/04/23 21:27:06 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

void	free_split(t_data *data)
{
	int	idx;

	idx = 0;
	while (data->lines_tab_split[idx])
	{
		free(data->lines_tab_split[idx]);
		idx++;
	}
	free(data->lines_tab_split);
}

int	to_int(t_data *data)
{
	data->info.n_philos = ft_atoi(data->lines_tab_split[0]);
	data->info.t_die = ft_atoi(data->lines_tab_split[1]);
	data->info.t_eat = ft_atoi(data->lines_tab_split[2]);
	data->info.t_sleep = ft_atoi(data->lines_tab_split[3]);
	if (data->ac == 6)
		data->info.t_must_eat = ft_atoi(data->lines_tab_split[4]);
	else
		data->info.t_must_eat = -1;
	free_split(data);
	return (0);
}
