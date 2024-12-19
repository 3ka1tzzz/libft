/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:44:13 by elopez-u          #+#    #+#             */
/*   Updated: 2024/10/18 12:51:57 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	word_count;

	if (!s)
		return (0);
	word_count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word_count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (word_count);
}

static char	*get_next_word(const char **s, char c)
{
	const char	*start;
	const char	*temp;
	size_t		length;

	if (!s || !**s)
		return (NULL);
	start = *s;
	while (*start == c)
		start++;
	if (!*start)
	{
		*s = start;
		return (NULL);
	}
	temp = start;
	while (*temp && *temp != c)
		temp++;
	length = temp - start;
	if (*temp)
		*s = temp + 1;
	else
		*s = temp;
	return (ft_substr(start, 0, length));
}

static void	free_split(char **result, int array_size)
{
	if (result)
	{
		while (array_size > 0)
			free(result[--array_size]);
		free(result);
	}
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		result[i] = get_next_word(&s, c);
		if (!result[i])
		{
			free_split(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
