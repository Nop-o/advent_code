/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamez-f <adamez-f@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:08:27 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/16 16:05:57 by adamez-f         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	long long	result;
	int			len;
	char		*str;
	char		**tab;

	printf("hello");
	len = get_file_len();
	str = get_file(len);
	tab = ft_split(str, '\n');
	if (!tab)
		return (-1);
	result = get_result(tab);
	printf("final result : %lli\n", result);
	free_all(tab);
	free(str);
	return (0);
}

//675845380984350 mine
//19605500130