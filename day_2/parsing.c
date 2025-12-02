/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:08:17 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/02 22:39:42 by nop_o            ###   ########.fr       */
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
}

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
	buffer[file_len] = '\0';
	read_check = read(fd, buffer, file_len);
	if (read_check < 0)
	{
		close(fd);
		return (NULL);
	}
	fill_str(buffer, &file);
	close(fd);
	return (file);
}
