/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:24:41 by rsaf              #+#    #+#             */
/*   Updated: 2022/04/23 21:25:43 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

int	ft_valid_bonus(int ch)
{
	if ((ch >= '0' && ch <= '9') || ch == ' ' || ch == '-' || ch == '+')
	{
		return (1);
	}
	return (0);
}

int	check_char_bonus(t_data *data)
{
	int	idx;

	idx = 0;
	while (data->join_line[idx])
	{
		if (!ft_valid_bonus(data->join_line[idx]))
			return (printf("Error: Found Charaters in the argument\n"), 1);
		if (ft_valid_bonus(data->join_line[idx])
			&& (data->join_line[idx + 1] == '-'
				|| data->join_line[idx + 1] == '+'))
			return (printf("Error: invalid argument\n"), 1);
		idx++;
	}
	return (0);
}
