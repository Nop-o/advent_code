/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:03:27 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/17 14:31:08 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	is_paper_roll_accesible(int x, int y, char **tab)
{
	int	adjacent_paper_roll;

	adjacent_paper_roll = 0;
	if (tab[x - 1][y] == PAPER_ROLL)
		adjacent_paper_roll++;
	if (tab[x][y - 1] == PAPER_ROLL)
		adjacent_paper_roll++;
	if (tab[x + 1][y] == PAPER_ROLL)
		adjacent_paper_roll++;
	if (tab[x][y + 1] == PAPER_ROLL)
		adjacent_paper_roll++;
	if (tab[x - 1][y - 1] == PAPER_ROLL)
		adjacent_paper_roll++;
	if (tab[x + 1][y - 1] == PAPER_ROLL)
		adjacent_paper_roll++;
	if (tab[x - 1][y + 1] == PAPER_ROLL)
		adjacent_paper_roll++;
	if (tab[x + 1][y + 1] == PAPER_ROLL)
		adjacent_paper_roll++;
	if (adjacent_paper_roll > 3)
		return (0);
	else 
		return (1);
}

unsigned int	get_result(char **board)
{
	unsigned int	result;
	int				x;
	int				y;

	result = 0;
	x = 0;
	while(board[x])
	{
		y = 0;
		while (board[x][y])
		{
			if (board[x][y] == PAPER_ROLL)
				if (is_paper_roll_accesible(x, y, board))
					result++;
			y++;
		}
		x++;
	}
	return (result);
}