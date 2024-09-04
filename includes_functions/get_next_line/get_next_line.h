/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:01:24 by iguliyev          #+#    #+#             */
/*   Updated: 2023/11/01 14:39:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_strchr_get(const char *s, int c);
size_t	ft_strlen_get(const char *s);
char	*ft_strdup_get(const char *src);
char	*ft_substr_get(const char *s, unsigned int start, size_t len);
char	*ft_strjoin_get(char const *s1, char const *s2);
char	*get_next_line(t_game *cub, int fd);

#endif
