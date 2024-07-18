/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:45:57 by jsakanov          #+#    #+#             */
/*   Updated: 2023/11/23 15:56:02 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_substrings(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (j);
}

static void	ft_free_string(char **s1, int n)
{
	int		i;

	if (s1 == NULL)
		return ;
	i = 0;
	while (i <= n)
	{
		free(s1[i]);
		i++;
	}
	free(s1);
}

static char	*ft_split_substring(const char *s, char c)
{
	char	*subs;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	while (i < len)
	{
		subs[i] = s[i];
		i++;
	}
	subs[len] = '\0';
	return (subs);
}

static char	**ft_write_str(const char *s, char **s1, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		s1[i] = ft_split_substring(s, c);
		if (!s1[i])
			return (ft_free_string(s1, i), NULL);
		i++;
		while (*s && *s != c)
			s++;
	}
	s1[i] = NULL;
	return (s1);
}

char	**ft_split(char const *s, char c)
{
	int			subs_count;
	char		**s1;

	if (s == NULL)
		return (NULL);
	subs_count = ft_count_substrings(s, c);
	s1 = (char **)malloc((subs_count + 1) * sizeof(char *));
	if (!s1)
		return (NULL);
	s1 = ft_write_str(s, s1, c);
	if (s1 == NULL)
		return (NULL);
	return (s1);
}
