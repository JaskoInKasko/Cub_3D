/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:35:08 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/18 11:30:07 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	m_size;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (((unsigned long int)(size * nmemb)) > 2147483647)
		return (NULL);
	m_size = (nmemb * size);
	ptr = malloc(m_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, m_size);
	return (ptr);
}
