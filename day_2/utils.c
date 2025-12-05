/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamez-f <adamez-f@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:08:04 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/05 17:39:59 by adamez-f         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		get_possible_id_len(char *nbr, int len)
{
	int		j;

	j = 1;
	while (nbr[j] && (nbr[0] != nbr[j]))
			j++;
		if(j == len)
			return (-1);
	return (j);
}

int	is_id_invalid(unsigned long long nb)
{
	char	*nbr;
	int		len;
	int		len_nbr_id;
	int		i;
	int		j;


	nbr = ft_itoa(nb);
	len = ft_strlen(nbr);
	if (len == 1)
		return (1);
	i = 0;
	j = 0;
	len_nbr_id = get_possible_id_len(nbr, len);
	if (len_nbr_id == -1)
		return (0);
	while (i < len - len_nbr_id)
	{
		j = len_nbr_id;
		while (i + j < len)
		{
			if (nbr[i] != nbr[i + j])
				return (0);
			j += len_nbr_id;
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
