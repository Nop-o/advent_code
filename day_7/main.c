/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:08:27 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/25 17:56:12 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	t_laser *result;
	int		file_len;
	char	*str;
	char	**christmas_tree;

	file_len = get_file_len();
	str = get_file(file_len);
	christmas_tree = ft_split(str, '\n');
	if (!christmas_tree)
		return (-1);
	free(str);
	result = get_result(christmas_tree);
	if (result == 0)
		return (-1);
	printf("final result : %u\n", result->laser_split);
	free(result->tab);
	free(result);
	return (0);
}
//8493