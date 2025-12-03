/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:08:04 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/03 18:02:16 by nop_o            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_id_invalid(unsigned long long nb)
{
	char	*nbr;
	int		len;
	int		i;

	nbr = ft_itoa(nb);
	len = ft_strlen(nbr);
	if (len % 2 == 1)
	{
		free(nbr);
		return (0);
	}
	i = 0;
	while (i < len / 2)
	{
		if (nbr[i] != nbr[(len / 2) + i])
		{
			free(nbr);
			return (0);
		}
		i++;
	}
	free(nbr);
	return (1);
}

char	**free_all(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
	split = NULL;
	return (split);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (((char *)s)[i])
		i++;
	return (i);
}
