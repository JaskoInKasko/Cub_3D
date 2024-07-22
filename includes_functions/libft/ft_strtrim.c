/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:08:46 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/15 13:49:12 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_check_char(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	startp;
	size_t	endp;
	char	*s2;

	i = 0;
	startp = 0;
	endp = ft_strlen(s1);
	while (s1[startp] != '\0' && ft_check_char(set, s1[startp]))
		startp++;
	while (endp > startp && ft_check_char(set, s1[endp - 1]))
		endp--;
	if (!s1)
		return (NULL);
	s2 = (char *)malloc(((((endp + 1) - startp) * sizeof(char))));
	if (!s2)
		return (NULL);
	while (startp < endp)
	{
		s2[i] = s1[startp];
		i++;
		startp++;
	}
	s2[i] = '\0';
	return (s2);
}
