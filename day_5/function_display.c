/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 19:47:40 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/21 19:56:36 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_board(char **board)
{
	int	i;

	i = 0;
	printf("\n\n\n\n\n\n");
	while (board[i])
		printf("%s\n", board[i++]);
}

void	print_list(t_int *lst)
{
	int	i;

	i = 0;
	printf("\n\n\n\n\n\n");
	while (lst)
	{
		printf("nb 1 :%lu - nb 2 : %lu\n", lst->nb1, lst->nb2);
		lst = lst->next;
	}
}

void	print_tab_int(unsigned long *tab, int size)
{
	int	i;

	i = 0;
	printf("\n\n\n\n\n\n");
	while (i < size)
		printf("%lu\n", tab[i++]);
}