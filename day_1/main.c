/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamez-f <adamez-f@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:03:23 by adamez-f          #+#    #+#             */
/*   Updated: 2025/12/02 15:41:29 by adamez-f         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_safe_code.h"

int	main(void)
{
	int		result;
	int		file_len;
	char	*file;

	file_len = get_file_len();
	if (file_len == -1)
		return (-1);
	file = get_file(file_len);
	if (!file)
		return (-1);
	result = get_result(file);
	printf("result = %d\n", result);
	return (0);
}
