/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:09:07 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/21 19:57:14 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# define ID_TO_CHECK "id_to_check.txt"
# define ID_RANGE "id_range.txt"

typedef struct s_int
{
	unsigned long	nb1;
	unsigned long	nb2;
	struct s_int	*next;
}	t_int;

//utils
char			**free_all(char **split);
void			lst_free_all(t_int **lst);
unsigned long	ft_atoi(char *nb);
int				ft_isdigit(int c);
//display
void			print_board(char **board);
void			print_list(t_int *lst);
void			print_tab_int(unsigned long *tab, int size);
//parsing
char			*get_file(int file_len, int wich_file);
int				get_file_len(int wich_file);
//split
char			**ft_split(char *s, char c);
//result
unsigned int	get_result(char **id_range, char **id_to_check);
unsigned long	get_list_nb(char *str);

#endif