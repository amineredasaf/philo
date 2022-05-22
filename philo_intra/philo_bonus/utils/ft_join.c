/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:45:12 by rsaf              #+#    #+#             */
/*   Updated: 2022/04/01 19:45:31 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

char	*ft_strjoin(char *dest, char *buff, int idx, int i)
{
	char	*ptr;

	if (!dest)
		dest = ft_dup(dest);
	if (!dest)
		return (NULL);
	if (!buff)
		return (NULL);
	ptr = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(dest) + 1));
	if (!ptr)
		return (printf("Error: Malloc problem\n"), NULL);
	if (dest)
		while (dest[++idx])
			ptr[idx] = dest[idx];
	while (buff[i])
		ptr[idx++] = buff[i++];
	ptr[idx] = '\0';
	free(dest);
	return (ptr);
}
