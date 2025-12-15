/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:13:05 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/15 22:29:06 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	lst_addback(t_list *new_node, t_list **list)
{
	t_list	*last_node;

	if (!list)
		*list = new_node;
	else
	{
		last_node = *list;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}

static long long	create_list(char **tab, t_list **list)
{
	t_list	*new_node;
	int		tab_len;

	tab_len = 0;
	while (tab[tab_len])
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return (-1);
		new_node->line = tab[tab_len];
		new_node->nb = 0;
		new_node->next = NULL;
		lst_addback(new_node, list);
		tab_len++;
	}
}

static long	add_all_node_nb(t_list *list)
{
	long	return_value;

	return_value = 0;
	while (list)
	{
		return_value += list->nb;
		list = list->next;
	}
	return (return_value);
}

static void	get_each_node_nb(t_list **list)
{
	t_list	*current_node;
	char	first_digit;
	char	second_digit;
	int		first_digit_pos;
	int		line_pos;

	current_node = *list;
	while (current_node)
	{
		first_digit = '0';
		while (current_node->line[line_pos])
		{
			if (current_node->line[line_pos] > first_digit && current_node->line[line_pos + 1])
			{
				first_digit = current_node->line[line_pos];
				first_digit_pos = line_pos;
			}
			line_pos++;
		}
		line_pos = first_digit_pos;
		second_digit = '0';
		while (current_node->line[++line_pos])
		{
			if (current_node->line[line_pos] > second_digit)
				second_digit = current_node->line[line_pos];
		}
		current_node->nb = ((first_digit - '0') * 10) + (second_digit - '0');
		current_node = current_node->next;
	}
}

long long	get_result(char **tab)
{
	long long	result;
	t_list		*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (-1);
	new_list->line = NULL;
	new_list->nb = 0;
	new_list->next = NULL;
	printf("hello");
	create_list(tab, &new_list);
	printf("hello");
	get_each_node_nb(&new_list);
	result = add_all_node_nb(new_list);
	return (result);
}