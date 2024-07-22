/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:06:47 by jsakanov          #+#    #+#             */
/*   Updated: 2023/11/27 15:07:03 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	int		len;
	char	*s3;

	len = 0;
	if (s1 == NULL || s2 == NULL)
		return (free(s1), NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	j = 0;
	s3 = (char *)malloc((len + 1) * sizeof(char));
	if (s3 == NULL)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i] != '\0')
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		s3[j++] = s2[i++];
	s3[j] = '\0';
	free(s1);
	return (s3);
}
