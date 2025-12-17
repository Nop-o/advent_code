/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:08:27 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/17 11:51:33 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	long long	result;
	int			len;
	char		*str;
	char		**tab;

	len = get_file_len();
	str = get_file(len);
	tab = ft_split(str, '\n');
	if (!tab)
		return (-1);
	result = get_result(tab);
	printf("final result : %lli\n", result);
	free(tab);
	free(str);
	return (0);
}
