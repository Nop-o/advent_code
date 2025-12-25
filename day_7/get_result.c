/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 17:38:49 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/25 18:52:44 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_laser	*init_laser(void)
{
	t_laser			*return_value;
	unsigned int	*tab_int;

	tab_int = NULL;
	tab_int[0] = 70;
	return_value = malloc(sizeof(t_laser));
	if (!return_value)
		return (NULL);
	return_value->tab = tab_int;
	return_value->size_tab = 1;
	return_value->laser_split = 0;
	return (return_value);
}

static int	is_there_a_laser_and_splitter(unsigned int column, t_laser *laser)
{
	unsigned int	i;

	i = 0;
	while (i < laser->size_tab)
	{
		if (laser->tab[i] == column)
			return (1);
		i++;
	}
	return (0);
}

static unsigned int	*adjust_laser(unsigned int column, t_laser *laser)
{
	unsigned int	*return_value;
	int				old_len;
	int				new_len;

	old_len = -1;
	new_len = 0;
	return_value = NULL;
	while (laser->tab[++old_len])
		if (column != laser->tab[old_len])
			return_value[new_len++] = laser->tab[old_len];
	if (!is_there_a_laser_and_splitter(column - 1, laser))
	{
		return_value[new_len++] = column - 1;
		laser->size_tab++;
	}
	if (!is_there_a_laser_and_splitter(column + 1, laser))
	{
		return_value[new_len++] = column + 1;
		laser->size_tab++;
	}
	return (return_value);
}

static void	find_laser_split_count(t_laser *laser, char **split)
{
	unsigned int	row;
	unsigned int	column;

	row = 0;
	while (split[row])
	{
		column = 0;
		while (split[row][column])
		{
			if (split[row][column] == '^' && is_there_a_laser_and_splitter(column, laser))
				laser->tab = adjust_laser(column, laser);
			column++;
		}
		row++;
	}
}

t_laser	*get_result(char **split)
{
	t_laser	*return_value;

	return_value = init_laser();
	if (!return_value)
		return (NULL);
	find_laser_split_count(return_value, split);
	free_all(split);
	return (return_value);
}