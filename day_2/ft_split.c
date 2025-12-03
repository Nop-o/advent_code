/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nop_o <nop_o@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:33:41 by adamez-f          #+#    #+#             */
/*   Updated: 2025/12/03 15:58:30 by nop_o            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	get_word_len(const char *s, int start, char c)
{
	int	len;

	len = 0;
	while (s[len + start] && s[len + start] != c)
		len++;
	return (len);
}

static int	get_word_count(const char *s, char c)
{
	int	i;
	int	words;

	words = 1;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static char	*fill_string(char *dest, const char *s, int start, char c)
{
	int	i;

	i = 0;
	while (s[start + i] && s[start + i] != c)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	i;
	size_t	size_allocation;

	if (nmemb == 0 || size == 0)
		size_allocation = 0;
	else if (size > 2147483647 / nmemb)
		return (0);
	else
		size_allocation = size * nmemb;
	tab = malloc(size_allocation);
	if (!tab)
		return (0);
	i = 0;
	while (i < size_allocation)
	{
		((char *)tab)[i] = 0;
		i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	split = (char **)ft_calloc(sizeof(char *), get_word_count(s, c));
	if (!split)
		return (0);
	i = 0;
	j = -1;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			return (split);
		split[++j] = (char *)malloc(get_word_len(s, i, c) + 1);
		if (!split[j])
			return (free_all(split));
		split[j] = fill_string(split[j], s, i, c);
		while (s[i] && s[i] != c)
			i++;
	}
	return (split);
}
