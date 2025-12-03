/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:13:05 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/03 18:00:13 by nop_o            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static unsigned long long	ft_atoi(const char *nptr, int pos)
{
	unsigned long long	nb;

	nb = 0;
	while (nptr[pos] && nptr[pos] >= '0' && nptr[pos] <= '9')
	{
		nb *= 10;
		nb += (nptr[pos++] - '0');
	}
	return (nb);
}

static void		get_id(unsigned long long *result, char *str, int *pos)
{
	unsigned long long	nb;
	unsigned long long	nb2;
	char			**tab;

	tab = ft_split(str, '-');
	nb = ft_atoi(tab[0], *pos);
	nb2 = ft_atoi(tab[1], *pos);
	free_all(tab);
	while (nb <= nb2)
	{
		if (is_id_invalid(nb))
			*result += nb;
		nb++;
	}
}

unsigned long long	get_result(char **tab)
{
	unsigned long long	result;
	int					i;
	int					j;

	i = 0;
	result = 0;
	while (tab[i])
	{
		j = 0;
		get_id(&result, tab[i], &j);
		i++;
	}
	return (result);
}