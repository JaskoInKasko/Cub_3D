/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:51:48 by jsakanov          #+#    #+#             */
/*   Updated: 2023/10/12 15:01:46 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned int	ft_print_uhex(unsigned int n, int len)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		len += ft_print_uhex(n / 16, 0);
		len += ft_print_uhex(n % 16, 0);
	}
	else if (n <= 16)
		len += ft_printchar(base[n]);
	return (len);
}
