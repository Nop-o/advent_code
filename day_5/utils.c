/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:08:04 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/21 19:47:21 by nop_o            ###   ########lyon.fr   */
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
	return (NULL);
}

void	lst_free_all(t_int **lst)
{
	t_int	*last_node;
	t_int	*current_node;

	if (!lst || !*lst)
		return ;
	current_node = *lst;
	while (current_node)
	{
		last_node = current_node;
		current_node = current_node->next;
		free(last_node); 
	}
	current_node = NULL;
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

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
