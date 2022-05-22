/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:24:53 by rsaf              #+#    #+#             */
/*   Updated: 2022/05/10 15:18:51 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	parsing_bonus(t_data *data)
{
	if (to_string_bonus(data) == 1)
		return (1);
	if (check_char_bonus(data) || to_splitted_bonus(data))
	{
		free(data->join_line);
		return (1);
	}
	if (to_int_bonus(data) || check_data_bonus(data))
		return (1);
	return (0);
}
