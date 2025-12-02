/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_safe_code.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamez-f <adamez-f@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:01:10 by adamez-f          #+#    #+#             */
/*   Updated: 2025/12/02 17:22:09 by adamez-f         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_SAFE_CODE_H
# define GET_SAFE_CODE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define FILE "text.txt"

//parsing
void	fill_str(char *buffer, char **file);
char	*get_file(int file_len);

//utils
int		get_file_len(void);
int		get_zero_count(int nb, int value);
void	get_nb(char *str, int *pos, int *return_value, int *result);
int		get_result(char *file);

#endif