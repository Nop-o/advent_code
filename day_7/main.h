/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:09:07 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/25 17:57:09 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# define FILE "input.txt"

typedef struct s_laser
{
	unsigned int	*tab;
	unsigned int	size_tab;
	unsigned int	laser_split;
}	t_laser ;

//utils
char			**free_all(char **split);
int				ft_isdigit(int c);
//display
void			print_board(char **board);
void			print_tab_int(unsigned long *tab, int size);
//parsing
char			*get_file(int file_len);
int				get_file_len(void);
//split
char			**ft_split(char *s, char c);
//result
t_laser			*get_result(char **tab);
#endif