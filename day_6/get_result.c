/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:03:27 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/21 23:34:17 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static	int	*create_tab_int(char **tab)
{
	int	len;
	int	*return_value;

	len = 0;
	while (tab[len])
		len++;
	return_value = malloc(sizeof(int) * len);
	if (!return_value)
		return (NULL);
	len = 0;
	while (tab[len])
	{
		return_value[len] = ft_atoi(tab[len]);
		len++;
	}
	return (return_value);
}

static int	**init_matrice(char ***matrice_str)
{
	int		**matrice_int;
	int		i;

	matrice_int = calloc(4, sizeof(int *));
	if (!matrice_int)
		return (0);
	i = -1;
	while (++i < 4)
		matrice_int[i] = create_tab_int(matrice_str[i]);
	return (matrice_int);
}

static unsigned long long	find_result(int **matrice, char **tab)
{
	unsigned long long	final_result;
	unsigned long long	temp_result;
	int					i;
	int					j;
	int					tab_size;

	tab_size = 0;
	while (tab[tab_size])
		tab_size++;
	printf("%d\n", tab_size);
	final_result = 0;
	i = -1;
	while (++i < tab_size)
	{
		j = 0;
		temp_result = matrice[j++][i];
		if (tab[i][0] == '+')
			while (j < 4)
				temp_result += matrice[j++][i];
		else
			while (j < 4)
				temp_result *= matrice[j++][i];
		final_result += temp_result;
	}
	return (final_result);
}

unsigned long long	get_result(char **tab)
{
	int					**matrice_int;
	char				***matrice_str;
	unsigned long long	return_value;

	matrice_str = calloc(6, sizeof(char **));
	if (!matrice_str)
		return (0);
	matrice_str[0] = ft_split(tab[0], ' ');
	matrice_str[1] = ft_split(tab[1], ' ');
	matrice_str[2] = ft_split(tab[2], ' ');
	matrice_str[3] = ft_split(tab[3], ' ');
	matrice_str[4] = ft_split(tab[4], ' ');
	if (!matrice_str[0] || !matrice_str[1] || !matrice_str[2] || !matrice_str[3] || !matrice_str[4])
	{
		free_matrice(matrice_str);
		return (0);
	}
	matrice_int = init_matrice(matrice_str);
	if (!matrice_int)
		return (0);
	return_value = find_result(matrice_int, matrice_str[4]);
	//free_matrice(matrice_str);
	//free_all_int(matrice_int, 1000);
	return (return_value);
}
