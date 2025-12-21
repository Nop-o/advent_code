/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:03:27 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/21 20:16:36 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	lst_addback(t_int **lst, t_int *new_node)
{
	t_int	*last_node;

	if (!*lst)
		*lst = new_node;
	else
	{
		last_node = *lst;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}

static void	create_list(char **tab, t_int	**list)
{
	int		i;
	int		j;
	t_int	*new_node;

	i = -1;
	while (tab[++i])
	{
		j = 0;
		new_node = malloc(sizeof(t_int));
		if (!new_node)
		{
			lst_free_all(list);
			return ;
		}
		new_node->nb1 = get_list_nb(tab[i]);
		while (tab[i][j] != '-')
			j++;
		new_node->nb2 = get_list_nb(tab[i] + j);
		new_node->next = NULL;
		lst_addback(list, new_node);
	}
}

static	unsigned long	*create_tab_ulong(char **tab)
{
	int				len;
	unsigned long	*return_value;

	len = 0;
	while (tab[len])
		len++;
	return_value = malloc(sizeof(unsigned long) * len);
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
static unsigned int	find_result(t_int *id_range, unsigned long *int_id_to_check)
{
	unsigned int	final_result;
	t_int *			reset_list;
	int				size_tab_ulong;
	int				i;

	size_tab_ulong = 1000;
	final_result = 0;
	reset_list = id_range;
	while (--size_tab_ulong >= 0)
	{
		id_range = reset_list;
		while (id_range)
		{
			if (*int_id_to_check >= id_range->nb1 && *int_id_to_check <= id_range->nb2)
			{
				final_result++;
				break ;
			}
			id_range = id_range->next;
		}
		int_id_to_check++;
	}
	return (final_result);
}

unsigned int	get_result(char **char_id_range, char **char_id_to_check)
{
	t_int			*int_id_range;
	unsigned long	*int_id_to_check;
	unsigned int	return_value;

	int_id_range = NULL;
	create_list(char_id_range, &int_id_range);
	if (!int_id_range)
		return (0);
	int_id_to_check = create_tab_ulong(char_id_to_check);
	if (!int_id_to_check)
		return (0);
	free_all(char_id_range);
	free_all(char_id_to_check);
	return_value = find_result(int_id_range, int_id_to_check);
	lst_free_all(&int_id_range);
	free(int_id_to_check);
	return (return_value);
}
