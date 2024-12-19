/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:00:02 by elopez-u          #+#    #+#             */
/*   Updated: 2024/10/18 12:46:27 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#if __SIZEOF_SIZE_T__ == 8 // For 64-bit platforms
# define SIZE_MAX 0xFFFFFFFFFFFFFFFFUL
#elif __SIZEOF_SIZE_T__ == 4 // For 32-bit platforms
# define SIZE_MAX 0xFFFFFFFFUL
#else
# error "Unsupported platform."
#endif

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tot_size;
	void	*ptr;

	if (nmemb && size > SIZE_MAX / nmemb)
		return (NULL);
	tot_size = nmemb * size;
	ptr = malloc(tot_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, tot_size);
	return (ptr);
}
