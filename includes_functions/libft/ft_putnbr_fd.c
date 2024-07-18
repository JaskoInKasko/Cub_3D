/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:41:39 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/16 13:01:17 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	negative(int *nb, int *minus, int fd)
{
	if (*nb == 0)
	{
		write (fd, "0", 1);
	}
	if (*nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*nb = 0;
		return (0);
	}
	else if (*nb < 0)
	{
		*nb *= -1;
		*minus = 1;
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[13];
	int		c;
	int		minus;

	c = 0;
	minus = 0;
	negative(&n, &minus, fd);
	while (n > 0)
	{
		str[c] = (n % 10) + 48;
		n = n / 10;
		c++;
	}
	if (minus == 1)
		str[c] = '-';
	else
		c--;
	while (c >= 0)
	{
		write(fd, &str[c], 1);
		c--;
	}
}
