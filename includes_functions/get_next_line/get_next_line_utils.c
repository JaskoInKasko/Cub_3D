/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguliyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:50:49 by iguliyev          #+#    #+#             */
/*   Updated: 2023/11/01 05:50:51 by iguliyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

char	*ft_strjoin_gnl(t_game *cub, char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	int		len;
	char	*s3;

	len = 0;
	if (s1 == NULL || s2 == NULL)
		return (free(s1), NULL);
	len = (ft_strlen_gnl(s1) + ft_strlen_gnl(s2));
	i = 0;
	j = 0;
	s3 = (char *)malloc((len + 1) * sizeof(char));
	if (s3 == NULL)
	{
		cub->flag.malloc_flag = 1;
		return (free(s1), NULL);
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

size_t	ft_strlen_gnl(const char *str)
{
	int	c;

	c = 0;
	if (str == NULL)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr_gnl(char *s, int c)
{
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strdup_gnl(t_game *cub, const char *s)
{
	size_t	i;
	size_t	size;
	char	*s1;

	i = 0;
	if (s == NULL)
		return (NULL);
	size = ft_strlen_gnl(s);
	s1 = (char *)malloc((size + 1) * sizeof(char));
	if (s1 == NULL)
	{
		cub->flag.malloc_flag = 1;
		return (NULL);
	}
	while (i < size)
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
