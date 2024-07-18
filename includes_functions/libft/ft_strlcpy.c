/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:00:10 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/14 12:08:27 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	c;
	size_t			len;	

	len = ft_strlen(src);
	c = 0;
	if (size == 0)
		return (len);
	while (src[c] != '\0' && c < size - 1)
	{
		dst[c] = src[c];
		c++;
	}
	dst[c] = '\0';
	return (len);
}
