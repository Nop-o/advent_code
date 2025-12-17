/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:08:04 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/17 11:55:31 by nop_o            ###   ########lyon.fr   */
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
	split = NULL;
	return (split);
}

void	lst_clear(t_list **list)
{
	t_list	*previous_node;

	while (*list)
	{
		previous_node = *list;
		*list = (*list)->next;
		free(previous_node->line);
		free(previous_node);
	}
	*list = NULL;
}

long long	add_all_node_nb(t_list *list)
{
	long long	return_value;

	return_value = 0;
	while (list)
	{
		return_value += list->nb;
		list = list->next;
	}
	return (return_value);
}

long long	ft_atoi(char *str)
{
	long long	return_value;

	return_value = 0;;
	while (*str)
		if (*str)
			return_value *= 10;
	
}