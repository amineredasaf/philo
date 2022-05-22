/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 02:56:08 by rsaf              #+#    #+#             */
/*   Updated: 2022/05/20 02:56:10 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

long long	apah(long long pers, long long past)
{
	return (pers - past);
}

void	resting(long long time, t_philo *philo)
{
	long long	start_resting;

	start_resting = time_now();
	while (!philo->dta->dead)
	{
		if (apah(time_now(), start_resting) >= time)
			break ;
		usleep(500);
	}
}
