/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:22:51 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/21 20:05:36 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

unsigned long	get_list_nb(char *str)
{
	unsigned long	return_value;

	while (*str && !ft_isdigit(*str))
		str++;
	return_value = ft_atoi(str);
	return (return_value);
}

//int	main(void)
//{
//	printf("%lu\n", get_list_nb("9prout98778e76salut"));
//	return (0);
//}