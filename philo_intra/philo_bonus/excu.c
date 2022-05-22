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

int	excu_bonus(t_data *data)
{
	int	nb_of_philo;

	nb_of_philo = data->info.n_philos;
	if (data != NULL)
	{
		if (init_sem(data) == 1)
			return (1);
		if (init_philo(data) == 1)
			return (1);
	}
	return (0);
}
