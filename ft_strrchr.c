/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:43:40 by elopez-u          #+#    #+#             */
/*   Updated: 2024/10/18 12:34:25 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	while (s[i])
		i++;
	uc = c;
	while (i >= 0)
	{
		if (s[i] == uc)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}
