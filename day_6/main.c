/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:08:27 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/21 23:02:25 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	unsigned long long	result;
	int					file_len;
	char				*str;
	char				**init_tab;

	file_len = get_file_len();
	str = get_file(file_len);
	init_tab = ft_split(str, '\n');
	free(str);
	result = get_result(init_tab);
	if (result == 0)
		return (-1);
	printf("final result : %llu\n", result);
	return (0);
}
//8493