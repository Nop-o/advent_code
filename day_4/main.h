/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:09:07 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/17 21:33:32 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# define FILE "text.txt"
# define PAPER_ROLL '@'
//utils
char	**free_all(char **split);
//parsing
int		get_file_len(void);
char	*get_file(int file_len);
//split
char	**ft_split(char const *s, char c);
//result
void	get_result(char **tab, unsigned int *result);

#endif