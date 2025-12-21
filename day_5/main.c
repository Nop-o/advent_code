/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:08:27 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/21 20:01:52 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	unsigned int	result;
	int				file_len;
	char			*str;
	char			*str2;
	char			**id_range;
	char			**id_to_check;

	file_len = get_file_len(1);
	str = get_file(file_len, 1);
	id_range = ft_split(str, '\n');
	free(str);
	file_len = get_file_len(2);
	str2 = get_file(file_len, 2);
	id_to_check = ft_split(str2, '\n');
	free(str2);
	result = get_result(id_range, id_to_check);
	if (result == 0)
		return (-1);
	printf("final result : %u\n", result);
	return (0);
}
//8493