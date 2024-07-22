/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:04:46 by jsakanov          #+#    #+#             */
/*   Updated: 2023/10/30 18:48:08 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int	ft_line_len(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static char	*ft_read_str(char *buffer, int fd)
{
	ssize_t	readb;
	char	*str;

	readb = 1;
	str = ft_strdup_gnl(buffer);
	if (!str)
		return (NULL);
	while (readb > 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		readb = read(fd, buffer, BUFFER_SIZE);
		if (readb == -1)
		{
			free(str);
			buffer[0] = '\0';
			return (NULL);
		}
		buffer[readb] = '\0';
		str = ft_strjoin_gnl(str, buffer);
		if (str == NULL)
			buffer[0] = '\0';
		if (str == NULL)
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	int			zero;
	static char	rest[BUFFER_SIZE + 1] = "";
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_str(rest, fd);
	if (str == NULL)
		return (NULL);
	if (str[0] == '\0')
		return (free(str), NULL);
	zero = ft_line_len(str);
	while (str[zero] && str[zero + i] != '\0')
	{
		rest[i] = str[zero + i];
		i++;
	}
	str[zero] = '\0';
	rest[i] = '\0';
	str[ft_strlen_gnl(str)] = '\0';
	if (!str)
		return (NULL);
	return (str);
}
