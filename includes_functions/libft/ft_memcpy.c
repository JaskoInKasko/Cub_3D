/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:40:48 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/14 11:40:17 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*c;
	char			*d;
	unsigned int	e;

	if (dest == NULL && src == NULL)
		return (NULL);
	c = (char *)dest;
	d = (char *)src;
	e = 0;
	while (e < n)
	{
		c[e] = d[e];
		e++;
	}
	return (dest);
}
