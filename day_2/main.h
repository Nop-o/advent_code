/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:09:07 by nop_o             #+#    #+#             */
/*   Updated: 2025/12/03 17:27:29 by nop_o            ###   ########.fr       */
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

//utils
size_t				ft_strlen(const char *s);
char				**free_all(char **split);
int					is_id_invalid(unsigned long long nb);

//parsing
int					get_file_len(void);
char				*get_file(int file_len);

//libft
char				*ft_itoa(unsigned long long n);
char				**ft_split(char const *s, char c);

//result
unsigned long long	get_result(char **tab);

#endif