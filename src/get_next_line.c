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

#include "../includes/Cub3D.h"

static void	ft_free_here(t_game *cub, char *backup, char *buffer, char *msg)
{
	if (backup)
	{
		free(backup);
		backup = NULL;
	}
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	ft_exit(cub, msg, EXIT_FAILURE);
}

static void	ft_first_read(t_game *cub, char **backup, char *buffer)
{
	*backup = ft_strdup_get("");
	if (!*backup)
		ft_free_here(cub, buffer, NULL, MALLOC);
}

static char	*doer(t_game *cub, int fd, char *buffer, char *backup)
{
	int		read_num;
	char	*temp;

	read_num = 1;
	while (1)
	{
		read_num = read(fd, buffer, BUFFER_SIZE);
		if (read_num < 0)
			ft_free_here(cub, backup, buffer,
				"Error: read() function failed!\n");
		else if (read_num == 0)
			return (backup);
		buffer[read_num] = '\0';
		if (backup == NULL)
			ft_first_read(cub, &backup, buffer);
		temp = backup;
		backup = ft_strjoin_get(temp, buffer);
		if (!backup)
			ft_free_here(cub, temp, buffer, MALLOC);
		ft_free(temp);
		if (ft_strchr_get(buffer, '\n'))
			return (backup);
	}
}

static char	*grab(t_game *cub, char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0')
		return (NULL);
	backup = ft_substr_get(line, count + 1, ft_strlen_get(line) - count);
	if (!backup)
	{
		free(line);
		ft_exit(cub, MALLOC, EXIT_FAILURE);
	}
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	cub->flag.backup = backup;
	return (backup);
}

char	*get_next_line(t_game *cub, int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup;

	if (fd < 0)
		ft_exit(cub, OPEN, EXIT_FAILURE);
	if (BUFFER_SIZE <= 0)
		ft_exit(cub, "Error: Invalid BUFFER_SIZE!\n", EXIT_FAILURE);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buffer)
	{
		free(backup);
		ft_exit(cub, MALLOC, EXIT_FAILURE);
	}
	line = doer(cub, fd, buffer, backup);
	if (line == NULL)
	{
		free(backup);
		backup = NULL;
	}
	free(buffer);
	buffer = NULL;
	if (line)
		backup = grab(cub, line);
	return (line);
}
/*
int main (void)
{
	char	*line;
	int my_fd;
	my_fd = open("my_file.txt", O_RDONLY);
	line = get_next_line(my_fd);
    printf("1. %s", line);// 1
	line = get_next_line(my_fd);
	printf("2. %s", line);// 2
    line = get_next_line(my_fd);
    printf("3. %s", line);// 3
    line = get_next_line(my_fd);
    printf("4. %s", line);// 4
    line = get_next_line(my_fd);
    printf("5. %s", line);// 5
    line = get_next_line(my_fd);
    printf("6. %s", line);// 6
    line = get_next_line(my_fd);
    printf("7. %s", line);// 7
    line = get_next_line(my_fd);
    printf("8. %s", line);// 8
    line = get_next_line(my_fd);
    printf("9. %s", line);// 9
    line = get_next_line(my_fd);
    printf("10. %s", line);// 10
    line = get_next_line(my_fd);
    printf("11. %s", line);// 11
    line = get_next_line(my_fd);
    printf("12. %s", line);// 12
    line = get_next_line(my_fd);
    printf("13. %s", line);// 13
    line = get_next_line(my_fd);
    printf("14. %s", line);// 14
    line = get_next_line(my_fd);
    printf("15. %s", line);// 15
    // line = myway(my_fd);
    // printf("16. %s\n\n", line);// 16
    // line = myway(my_fd);
    // printf("17. %s\n\n", line);// 17
    // line = myway(my_fd);
    // printf("18. %s\n\n", line);// 18
    // line = myway(my_fd);
    // printf("19. %s\n\n", line);// 19
    // line = myway(my_fd);
    // printf("20. %s\n\n", line);// 20
    // line = myway(my_fd);
    // printf("21. %s\n\n", line);// 21
    // line = myway(my_fd);
    // printf("22. %s\n\n", line);// 22
    // line = myway(my_fd);
    // printf("23. %s\n\n", line);// 23
    return(0);
}*/
