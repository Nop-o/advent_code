/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:08:17 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/21 19:42:29 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_file_len(int wich_file)
{
	int		fd;
	int		file_len;
	int		bytes_read;
	char	buffer[4096];

	if (wich_file == 1)
		fd = open(ID_RANGE, O_RDONLY);
	else 
		fd = open(ID_TO_CHECK, O_RDONLY);
	if (fd < 0)
		return (-1);
	file_len = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 4096);
		if (bytes_read < 0)
			return (-1);
		file_len += bytes_read;
	}
	close(fd);
	return (file_len);
}

char	*get_file(int file_len, int wich_file)
{
	int		fd;
	char	*return_value;
	int		read_check;

	if (wich_file == 1)
		fd = open(ID_RANGE, O_RDONLY);
	else 
		fd = open(ID_TO_CHECK, O_RDONLY);
	if (fd < 0)
		return (NULL);
	return_value = malloc(file_len + 1);
	if (!return_value)
	{
		close(fd);
		return (NULL);
	}
	read_check = read(fd, return_value, file_len);
	close(fd);
	if (read_check < 0)
	{
		free(return_value);
		return (NULL);
	}
	return_value[file_len] = '\0';
	return (return_value);
}
