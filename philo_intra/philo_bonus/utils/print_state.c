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
	if ((!philo->is_dead))
	{
		sem_wait(philo->dta->write_sem);
		printf("[%lld]", time_now() - philo->t_born);
		printf(" philo %d %s\n", philo->id, str);
		sem_post(philo->dta->write_sem);
	}
}
