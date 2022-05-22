/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:45:46 by rsaf              #+#    #+#             */
/*   Updated: 2022/04/01 19:45:51 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

int	ft_countr(const char *s, char c)
{
	int	idx;
	int	word;

	word = 0;
	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] != c && (s[idx + 1] == c || s[idx + 1] == '\0'))
			word++;
		idx++;
	}
	return (word);
}

char	*ft_addwords(char *dest, const char *s, int len)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		dest[idx] = s[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

int	ft_move2tab(char **dest, const char *s, char sep)
{
	int	len;
	int	idx;
	int	word;

	len = 0;
	idx = 0;
	word = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == sep)
			idx++;
		else
		{
			len = 0;
			while (s[idx + len] != sep && s[idx + len] != '\0')
				len++;
			dest[word] = malloc(sizeof(char) * (len + 1));
			if (dest[word] == NULL)
				return (1);
			ft_addwords(dest[word], &s[idx], len);
			idx = idx + len;
			word++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**tab;

	if (!s)
		return (NULL);
	word = ft_countr(s, c);
	if (word == 0)
		return (printf("Error: No words\n"), NULL);
	tab = malloc(sizeof(char *) * (word + 1));
	if (!tab)
		return (printf("Error: Malloc problem\n"), NULL);
	tab[word] = 0;
	if (ft_move2tab(tab, s, c) == 1)
		return (printf("Error: Malloc problem\n"), NULL);
	return (tab);
}
