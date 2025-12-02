/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:00:04 by adamez-f          #+#    #+#             */
/*   Updated: 2025/12/02 22:38:08 by nop_o            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_safe_code.h"

static void	fill_str(char *buffer, char **file)
{
	static int	i;
	int			j;

	if (!*file)
		i = 0;
	j = 0;
	while (buffer[j])
	{
		(*file)[i++] = buffer[j++];
	}
}

char	*get_file(int file_len)
{
	int		fd;
	char	*file;
	char	buffer[4097];
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
	file[file_len] = '\0';
	read_check = 1;
	while (read_check > 0)
	{
		buffer[4096] = '\0';
		read_check = read(fd, buffer, 4096);
		if (read_check < 0)
		{
			close(fd);
			return (NULL);
		}
		buffer[read_check] = '\0';
		fill_str(buffer, &file);
	}
	close(fd);
	return (file);
}
