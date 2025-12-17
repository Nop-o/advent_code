/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:08:17 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/17 12:58:02 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	fill_str(char *buffer, char **file)
{
	static int	i;
	int			j;

	if (!*file)
		i = 0;
	j = 0;
	while (buffer[j])
		(*file)[i++] = buffer[j++];
	(*file)[i] = '\0';
}

int	get_file_len(void)
{
	int		fd;
	int		file_len;
	int		bytes_read;
	char	buffer[4096];

	fd = open(FILE, O_RDONLY);
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

char	*get_file(int file_len)
{
	int		fd;
	char	*file;
	char	buffer[file_len + 1];
	int		read_check;

	fd = open(FILE, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = malloc(file_len + 1);
	if (!file)
	{
		close(fd);
		return (NULL);
	}
	read_check = read(fd, buffer, file_len);
	close(fd);
	if (read_check < 0)
		return (NULL);
	buffer[file_len] = '\0';
	fill_str(buffer, &file);
	return (file);
}
