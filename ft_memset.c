/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:07:46 by elopez-u          #+#    #+#             */
/*   Updated: 2024/10/18 11:50:06 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	value;

	if (n == 0)
		return (s);
	ptr = (unsigned char *)s;
	value = (unsigned char)c;
	while (n > 0)
	{
		*ptr++ = value;
		n--;
	}
	return (s);
}
