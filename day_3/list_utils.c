/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:00:27 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/17 12:18:09 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_list	*lst_addback(t_list *new_node, t_list **list)
{
	t_list	*last_node;

	if (!*list || !list)
		*list = new_node;
	else
	{
		last_node = *list;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}

void	create_list(char **tab, t_list **list)
{
	t_list	*new_node;
	int		tab_len;

	tab_len = 0;
	while (tab[tab_len])
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			lst_clear(list);
			return ;
		}
		new_node->line = tab[tab_len];
		new_node->nb = 0;
		new_node->next = NULL;
		lst_addback(new_node, list);
		tab_len++;
	}
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

unsigned long long	add_all_node_nb(t_list *list)
{
	unsigned long long	return_value;

	return_value = 0;
	while (list)
	{
		return_value += list->nb;
		list = list->next;
	}
	return (return_value);
}
