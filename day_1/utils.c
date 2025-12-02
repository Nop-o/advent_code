/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamez-f <adamez-f@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:17:39 by adamez-f          #+#    #+#             */
/*   Updated: 2025/12/02 17:20:32 by adamez-f         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_safe_code.h"

int	get_file_len(void)
{
	int		fd;
	int		file_len;
	int		bytes_read;
	char	buffer[4097];

	fd = open(FILE, O_RDONLY);
	if (fd < 0)
		return (-1);
	file_len = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		buffer[4096] = '\0';
		bytes_read = read(fd, buffer, 4096);
		file_len += bytes_read;
	}
	close(fd);
	return (file_len);
}
int	get_zero_count(int nb, int value)
{
	int	i;
	int	return_value;
	int	sign;

	sign = 1;
	if (value < 0)
	{
		value *= -1;
		sign = -1;
	}
	i = 0;
	return_value = 0;
	while (i < value)
	{
		if (nb % 100 == 0)
			return_value++;
		i++;
		if (sign == 1)
			nb++;
		else
			nb--;
	}
	return (return_value);
}

void	get_nb(char *str, int *pos, int *return_value, int *nb)
{
	int	sign;
	int	helper;

	sign = 1;
	if (str[*pos] == 'L' || str[*pos] == 'R')
		(*pos)++;
	if (str[(*pos) - 1] == 'L')
		sign = -1;
	helper = 0;
	while (str[*pos] >= '0' && str[*pos] <= '9')
	{
		helper *= 10;
		helper += str[*pos] - '0';
		(*pos)++;
	}
	helper *= sign;
	*return_value += get_zero_count(*nb, helper);
	*nb += helper;
	*nb %= 100;
}


int	get_result(char *file)
{
	int	result;
	int	i;
	int	return_value;

	return_value = 0;
	result = 50;
	i = 0;
	while (file[i])
	{
		while (file[i] && file[i] != 'L' && file[i] != 'R')
			i++;
		get_nb(file, &i, &return_value, &result);
		if (result < 0)
			result += 100;
		else if (result > 99)
			result -= 100;
	}
	free(file);
	return (return_value);
}
