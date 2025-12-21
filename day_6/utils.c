/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:08:04 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/21 23:33:30 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**free_all(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

int	**free_all_int(int **split, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(split[i++]);
	free(split);
	return (NULL);
}

void	free_matrice(char ***matrice)
{
	while (*matrice)
	{
		free_all(*matrice);
		matrice++;
	}
	free(matrice);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

unsigned long	ft_atoi(char *nb)
{
	unsigned long	return_value;

	return_value = 0;
	while (*nb && ft_isdigit(*nb))
	{
		return_value *= 10;
		return_value += *nb - '0';
		nb++;
	}
	return (return_value);
}
