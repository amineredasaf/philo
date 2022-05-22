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

int	init_sem(t_data *data)
{
	sem_unlink("forks_sem");
	sem_unlink("eating_sem");
	sem_unlink("writing_sem");
	data->forks_sem = sem_open("forks_sem", O_CREAT, 0700, data->info.n_philos);
	data->eating_sem = sem_open("eating_sem", O_CREAT, 0700, 1);
	data->write_sem = sem_open("writing_sem", O_CREAT, 0700, 1);
	if (data->eating_sem == SEM_FAILED || data->forks_sem == SEM_FAILED
		|| data->write_sem == SEM_FAILED)
		return (1);
	return (0);
}

void	*dead_check(void *ptr)
{
	int	idx;
	long long	now;
	t_philo *philo;

	idx = 0;
	philo = (t_philo *)ptr;
	while (1)
	{
		now = time_now();
		if ((philo->id == philo->dta->info.n_philos && philo->total_m == philo->dta->info.t_must_eat) 
			|| (now - philo->l_meal >= philo->dta->info.t_die))
		{
			philo->is_dead = 1;
			sem_wait(philo->dta->write_sem);
			printf("[%lld] philo ", time_now() - philo->t_born);
			printf("%d is dead\n", philo->id);
			while (idx < philo->dta->info.n_philos)
				kill(philo->dta->pid[idx++], SIGINT);
			sem_close(philo->dta->forks_sem);
			sem_close(philo->dta->write_sem);
			sem_close(philo->dta->eating_sem);
			sem_unlink("forks_sem");
			sem_unlink("eating_sem");
			sem_unlink("writing_sem");
			break ;
		}
	}
	return (NULL);
}

void	is_eating(t_philo *philo)
{
	sem_wait(philo->dta->forks_sem);
	print_state(philo, "Has take a fork");
	sem_wait(philo->dta->forks_sem);
	print_state(philo, "Has take a fork");
	print_state(philo, "is eating");
	philo->l_meal = time_now();
	resting(philo->dta->info.t_eat, philo);
	philo->total_m++;
	sem_post(philo->dta->forks_sem);
	sem_post(philo->dta->forks_sem);

}

void	routine(t_philo *philo)
{
	while (!philo->is_dead)
	{
		is_eating(philo);
		print_state(philo, "is sleeping");
		resting(philo->dta->info.t_sleep, philo);
		print_state(philo, "is thinking");
	}
}

void	spwan(t_data *data, int idx)
{
	data->philo[idx].dta = data;
	data->philo[idx].id = idx + 1;
	data->philo[idx].is_dead = 0;
	data->philo[idx].total_m = 0;
	data->philo[idx].t_born = time_now();
	data->philo[idx].l_meal = time_now();
	pthread_create(&data->philo[idx].thread, NULL, &dead_check, &data->philo[idx]);
	routine(&data->philo[idx]);
	pthread_detach(data->philo[idx].thread);
}

int	init_philo(t_data *data)
{
	int idx;

	idx = 0;
	while (idx < data->info.n_philos)
	{
		data->pid[idx] = fork();
		if (data->pid[idx] == 0)
			spwan(data, idx);
		idx++;
	}
	idx = 0;
	while (idx < data->info.n_philos)
	{
		waitpid(data->pid[idx], 0, 0);
		idx++;
	}
	return (0);
}
