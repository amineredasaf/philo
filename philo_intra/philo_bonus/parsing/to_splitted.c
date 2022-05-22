/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_splitted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:27:37 by rsaf              #+#    #+#             */
/*   Updated: 2022/04/23 21:27:51 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

int	to_splitted_bonus(t_data *data)
{
	data->lines_tab_split = ft_split(data->join_line, ' ');
	if (data->lines_tab_split == NULL)
		return (1);
	free(data->join_line);
	return (0);
}
