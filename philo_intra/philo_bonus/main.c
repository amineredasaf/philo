/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:23:55 by rsaf              #+#    #+#             */
/*   Updated: 2022/05/10 15:18:29 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		data.av = av;
		data.ac = ac;
		if (parsing_bonus(&data) == 1)
			return (1);
		if (excu_bonus(&data) == 1)
			return (1);
	}
	else
		ft_putstr("Error: The Arguments Are Not Correct\n");
	return (0);
}
