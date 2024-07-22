/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:41:01 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/14 19:36:05 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_asign(char const *s1, char const *s2, char *s3)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s3[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s3[j] = s2[i];
		i++;
		j++;
	}
	s3[j] = '\0';
	return (s3);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;

	len = (ft_strlen(s1) + ft_strlen(s2));
	if (s1 == 0 || s2 == 0)
		return (NULL);
	s3 = (char *)malloc((len + 1) * sizeof(char));
	if (s3 == 0)
		return (NULL);
	s3 = ft_asign(s1, s2, s3);
	return (s3);
}
