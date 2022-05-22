/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 02:55:57 by rsaf              #+#    #+#             */
/*   Updated: 2022/05/20 02:56:00 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

void	print_state(t_philo *philo, char *str)
{
	if ((!philo->dta->dead))
	{
		pthread_mutex_lock(&philo->dta->write_m);
		printf("[%lld]", time_now() - philo->t_born);
		printf(" philo %d %s\n", philo->id, str);
		pthread_mutex_unlock(&philo->dta->write_m);
	}
}
