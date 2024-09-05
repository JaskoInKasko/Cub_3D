/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:50:15 by iguliyev          #+#    #+#             */
/*   Updated: 2023/11/01 14:48:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

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

static char	*ft_read_str(t_game *cub, char *buffer, int fd)
{
	ssize_t	readb;
	char	*str;

	readb = 1;
	str = ft_strdup_gnl(cub, buffer);
	if (!str)
		return (NULL);
	while (readb > 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		readb = read(fd, buffer, BUFFER_SIZE);
		if (readb == -1)
		{
			free(str);
			buffer[0] = '\0';
			cub->flag.read_flag = 1;
			return (NULL);
		}
		buffer[readb] = '\0';
		str = ft_strjoin_gnl(cub, str, buffer);
		if (str == NULL)
			buffer[0] = '\0';
		if (str == NULL)
			break ;
	}
	return (str);
}

char	*get_next_line(t_game *cub, int fd)
{
	char		*str;
	int			zero;
	static char	rest[BUFFER_SIZE + 1] = "";
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_str(cub, rest, fd);
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
