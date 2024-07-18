/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:22:51 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/11 18:47:17 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	size;
	char	*s1;

	i = 0;
	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	s1 = (char *)malloc((size + 1) * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	while (i < size)
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
