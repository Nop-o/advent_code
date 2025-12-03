/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:08:27 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/03 18:00:00 by nop_o            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	unsigned long long	result;
	int					len;
	char				*str;
	char				**tab;

	len = get_file_len();
	str = get_file(len);
	tab = ft_split(str, ',');
	if (!tab)
		return (-1);
	result = get_result(tab);
	printf("final result : %llu\n", result);
	free_all(tab);
	free(str);
	return (0);
}

//675845380984350 mine
//19605500130