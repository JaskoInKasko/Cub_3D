/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:33:43 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/16 13:06:42 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_min_int(void)
{
	char	*s;

	s = (char *)malloc(12 * sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcpy(s, "-2147483648", 12);
	return (s);
}

static int	ft_get_int_length(int n, int len)
{
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static char	*ft_malloc_str_asign(int n, int nb, int len)
{
	char	*s;

	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (n == 0)
		s[0] = '0';
	s[len] = '\0';
	while (len >= 0 && n != 0)
	{
		len--;
		s[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (nb == 1)
		s[len - 1] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		nb;

	nb = 0;
	len = 0;
	if (n == -2147483648)
		return (ft_min_int());
	if (n < 0)
	{
		n = n * (-1);
		nb = 1;
		len++;
	}
	len = ft_get_int_length(n, len);
	s = ft_malloc_str_asign(n, nb, len);
	return (s);
}
