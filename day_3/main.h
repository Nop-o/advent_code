/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:09:07 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/17 11:53:01 by nop_o            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

#define FILE "text.txt"

typedef struct s_list
{
	char			*line;
	long long		nb;
	struct s_list	*next;
}	t_list;

//utils
char		**free_all(char **split);
void		lst_clear(t_list **list);
long long	add_all_node_nb(t_list *list);

//parsing
int			get_file_len(void);
char		*get_file(int file_len);

//split
char		**ft_split(char const *s, char c);

//result
long long	get_result(char **tab);

#endif