/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:26:37 by rsaf              #+#    #+#             */
/*   Updated: 2022/04/23 20:27:27 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

int	verify_blankspace_bonus(t_data *data, int idx, int idy, int found)
{
	while (data->av[idx])
	{
		idy = 0;
		while (data->av[idx][idy])
		{
			if (found != 1 && data->av[idx][idy] >= '0'
			&& data->av[idx][idy] <= '9')
				found = 1;
			if (found == 1 && data->av[idx][idy] == ' '
			&& (data->av[idx][idy + 1] >= '0' && data->av[idx][idy + 1] <= '9'))
				return (1);
			idy++;
		}
		if (found == 1)
		{
			found = 0;
			idx++;
		}
		else
			return (1);
	}
	return (0);
}

int	to_string_bonus(t_data *data)
{
	int	idx;

	idx = 1;
	data->join_line = NULL;
	if (verify_blankspace_bonus(data, 1, 0, 0) == 1)
		return (printf("Error: invalide argument.\n"), 1);
	while (data->av[idx])
	{
		data->join_line = ft_strjoin(data->join_line, data->av[idx], -1, 0);
		if (data->join_line == NULL)
			return (1);
		data->join_line = ft_strjoin(data->join_line, " ", -1, 0);
		idx++;
	}
	return (0);
}
