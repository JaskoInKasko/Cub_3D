/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:10:00 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/10 17:13:46 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lsrc;
	size_t	ldest;

	lsrc = ft_strlen(src);
	ldest = ft_strlen(dst);
	i = 0;
	if (size == 0)
		return (lsrc);
	while (src[i] != '\0' && (ldest + i) < size - 1)
	{
		dst[ldest + i] = src[i];
		i++;
	}
	if (size < ldest)
		return (lsrc + size);
	dst[ldest + i++] = '\0';
	return (lsrc + ldest);
}
