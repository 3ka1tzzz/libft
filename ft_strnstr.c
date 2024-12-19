/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:28:27 by elopez-u          #+#    #+#             */
/*   Updated: 2024/10/18 12:34:18 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	little_len = ft_strlen(little);
	if (len == 0 || little_len > len)
		return (NULL);
	i = 0;
	while (big[i] && i + little_len <= len)
	{
		j = 0;
		while (little[j] && big[i + j] == little[j])
			j++;
		if (j == little_len)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
