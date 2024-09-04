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

#include "../includes/Cub3D.h"

char	*ft_strchr_get(const char *s, int c)
{
	int		i;
	char	*p1;
	char	p2;

	i = 0;
	p1 = (char *)s;
	p2 = (char)c;
	while (s[i])
	{
		if (s[i] == p2)
			return (p1);
		i++;
		p1++;
	}
	if (s[i] == p2)
		return (p1);
	return (NULL);
}

size_t	ft_strlen_get(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_get(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc((ft_strlen_get(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr_get(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*m;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen_get(s))
		return (ft_strdup_get(""));
	if (len > ft_strlen_get(s) - start)
		len = ft_strlen_get(s) - start;
	m = (char *)malloc((len + 1) * sizeof(char));
	if (!m)
		return (NULL);
	while (len > 0)
	{
		m[i] = s[start];
		i++;
		start++;
		len--;
	}
	m[i] = '\0';
	return (m);
}

char	*ft_strjoin_get(char const *s1, char const *s2)
{
	char	*m;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	m = (char *)malloc(sizeof(char) * (ft_strlen_get(s1)
				+ ft_strlen_get(s2) + 1));
	if (m == NULL)
		return (NULL);
	while (s1[i])
	{
		m[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		m[j] = s2[i];
		i++;
		j++;
	}
	m[j] = '\0';
	return (m);
}
