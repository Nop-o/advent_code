/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:13:05 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/17 12:59:15 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	get_each_node_nb(t_list **list)
{
	int		final_nb_len;
	t_list	*current_node;
	int		digit;
	int		digit_pos;
	int		line_pos;

	current_node = *list;
	while (current_node)
	{
		digit_pos = -1;
		final_nb_len = 11;
		while (final_nb_len >= 0)
		{
			digit = 0;
			line_pos = digit_pos + 1;
			while (current_node->line[line_pos + final_nb_len])
			{
				if (current_node->line[line_pos] - '0' > digit)
				{
					digit = current_node->line[line_pos] - '0';
					digit_pos = line_pos;
				}
				line_pos++;
			}
			current_node->nb = (10 * current_node->nb) + digit;
			final_nb_len--;
		}
		current_node = current_node->next;
	}
}

unsigned long long	get_result(char **tab)
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
