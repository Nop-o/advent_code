/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:05:22 by adamez-f          #+#    #+#             */
/*   Updated: 2025/12/03 17:47:22 by nop_o            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_power(int nb, int pow)
{
	int	i;
	int	result;

	result = nb;
	i = 1;
	while (i < pow)
	{
		result *= nb;
		i++;
	}
	return (result);
}

static char	*fill_itoa(unsigned long long nb, int pos, int size, char *itoa)
{
	int		helper;

	while (pos < size - 1)
	{
		helper = (nb / ft_power(10, (size - pos) - 1));
		itoa[pos] = (helper % 10) + '0';
		pos++;
	}
	itoa[pos++] = (nb % 10) + '0';
	itoa[pos] = '\0';
	return (itoa);
}

static int	get_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(unsigned long long n)
{
	int		i;
	int		len;
	char	*itoa;

	i = 0;
	len = get_len(n);
	itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (0);
	itoa = fill_itoa(n, i, len, itoa);
	return (itoa);
}
