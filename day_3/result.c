/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:13:05 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/17 11:50:52 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_list	*lst_addback(t_list *new_node, t_list **list)
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

static void	create_list(char **tab, t_list **list)
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

static void	get_each_node_nb(t_list **list)
{
	t_list	*current_node;
	char	digit;
	int		digit_pos;
	int		line_pos;

	current_node = *list;
	while (current_node)
	{
		digit = 0;
		line_pos = 0;
		while (current_node->line[line_pos])
		{
			if (current_node->line[line_pos] > digit && current_node->line[line_pos + 1])
			{
				digit = current_node->line[line_pos];
				digit_pos = line_pos;
			}
			line_pos++;
		}
		current_node->nb = 10 * (digit - '0');
		digit = 0;
		while (current_node->line[++digit_pos])
			if (current_node->line[digit_pos] > digit)
				digit = current_node->line[digit_pos];
		current_node->nb += (digit - '0');
		current_node = current_node->next;
	}
}

long long	get_result(char **tab)
{
	long long	result;
	t_list		*new_list;

	result = 0;
	new_list = NULL;
	create_list(tab, &new_list);
	get_each_node_nb(&new_list);
	result = add_all_node_nb(new_list);
	lst_clear(&new_list);
	return (result);
}